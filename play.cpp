#include <bits/stdc++.h>
using namespace std;

typedef uint64_t Block;
class DBitset
{
    int n;
    vector<Block> bits;

public:
    DBitset() : n(0) {}
    DBitset(int size) : n(size), bits((size + 63) / 64) {}
    void init(int size)
    {
        n = size;
        bits.assign((n + 63) / 64, 0);
    }
    void setAll()
    {
        for (auto &b : bits)
            b = ~0ULL;
        trim();
    }
    void set(int i) { bits[i >> 6] |= 1ULL << (i & 63); }
    bool test(int i) const { return bits[i >> 6] & (1ULL << (i & 63)); }
    size_t count() const
    {
        size_t c = 0;
        for (auto b : bits)
            c += __builtin_popcountll(b);
        return c;
    }

    DBitset operator&(const DBitset &o) const
    {
        DBitset r(n);
        for (size_t i = 0; i < bits.size(); ++i)
            r.bits[i] = bits[i] & o.bits[i];
        return r;
    }
    DBitset operator|(const DBitset &o) const
    {
        DBitset r(n);
        for (size_t i = 0; i < bits.size(); ++i)
            r.bits[i] = bits[i] | o.bits[i];
        return r;
    }
    void operator&=(const DBitset &o)
    {
        for (size_t i = 0; i < bits.size(); ++i)
            bits[i] &= o.bits[i];
    }
    void operator|=(const DBitset &o)
    {
        for (size_t i = 0; i < bits.size(); ++i)
            bits[i] |= o.bits[i];
    }

private:
    void trim()
    {
        int extra = bits.size() * 64 - n;
        if (extra > 0)
            bits.back() &= (~0ULL >> extra);
    }
};

static const int ROWS = 10, COLS = 10;
static const int TOTAL = ROWS * COLS;

struct Placement
{
    int headIdx;
    DBitset occupancy;
    Placement() : occupancy(TOTAL) {}
};

class Adversary
{
public:
    Adversary()
    {
        generatePlacements();
        generateTriples();
        initLookup();
        current.init(triplesCount);
        current.setAll();
    }

    int respond(int moveIdx)
    {
        array<size_t, 3> counts = {0, 0, 0};
        for (int v = 0; v < 3; ++v)
        {
            DBitset temp = current & verdictLookup[moveIdx][v];
            counts[v] = temp.count();
        }
        int bestV = max_element(counts.begin(), counts.end()) - counts.begin();
        current &= verdictLookup[moveIdx][bestV];
        return bestV;
    }

    size_t remaining() const { return current.count(); }
    const vector<Placement> &getPlacements() const { return placements; }
    const vector<array<int, 3>> &getTriples() const { return triples; }
    const DBitset &getCurrent() const { return current; }

private:
    vector<Placement> placements;
    vector<array<int, 3>> triples;
    int triplesCount;
    vector<DBitset> tripleOccupancy;
    vector<array<DBitset, 3>> verdictLookup;
    DBitset current;

    pair<int, int> rotate(const pair<int, int> &p, int k)
    {
        int x = p.first, y = p.second;
        while (k--)
        {
            int nx = -y, ny = x;
            x = nx;
            y = ny;
        }
        return {x, y};
    }

    void generatePlacements()
    {
        vector<pair<int, int>> base = {
            {0, 0}, {-2, -1}, {-1, -1}, {0, -1}, {1, -1}, {2, -1}, {0, -2}, {-1, -3}, {0, -3}, {1, -3}};
        for (int r = 0; r < ROWS; ++r)
        {
            for (int c = 0; c < COLS; ++c)
            {
                for (int k = 0; k < 4; ++k)
                {
                    Placement p;
                    bool ok = true;
                    for (auto &bp : base)
                    {
                        auto off = rotate(bp, k);
                        int rr = r + off.first;
                        int cc = c + off.second;
                        if (rr < 0 || rr >= ROWS || cc < 0 || cc >= COLS)
                        {
                            ok = false;
                            break;
                        }
                        int idx = rr * COLS + cc;
                        p.occupancy.set(idx);
                        if (bp.first == 0 && bp.second == 0)
                            p.headIdx = idx;
                    }
                    if (ok)
                        placements.push_back(p);
                }
            }
        }
    }

    void generateTriples()
    {
        int n = placements.size();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if ((placements[i].occupancy & placements[j].occupancy).count() == 0)
                    for (int k = j + 1; k < n; ++k)
                        if ((placements[i].occupancy & placements[k].occupancy).count() == 0 &&
                            (placements[j].occupancy & placements[k].occupancy).count() == 0)
                            triples.push_back({i, j, k});
        triplesCount = triples.size();
        tripleOccupancy.reserve(triplesCount);
        for (auto &t : triples)
        {
            DBitset m;
            m.init(TOTAL);
            m |= placements[t[0]].occupancy;
            m |= placements[t[1]].occupancy;
            m |= placements[t[2]].occupancy;
            tripleOccupancy.push_back(m);
        }
    }

    void initLookup()
    {
        verdictLookup.resize(TOTAL);
        for (int cell = 0; cell < TOTAL; ++cell)
            for (int v = 0; v < 3; ++v)
                verdictLookup[cell][v].init(triplesCount);
        for (int t = 0; t < triplesCount; ++t)
        {
            auto &occ = tripleOccupancy[t];
            auto &inds = triples[t];
            for (int cell = 0; cell < TOTAL; ++cell)
            {
                int v = 0;
                if (occ.test(cell))
                {
                    if (cell == placements[inds[0]].headIdx || cell == placements[inds[1]].headIdx || cell == placements[inds[2]].headIdx)
                        v = 2;
                    else
                        v = 1;
                }
                verdictLookup[cell][v].set(t);
            }
        }
    }
};

// Parse input like "A1" .. "J10" to index 0-99
bool parseCoord(const string &s, int &idx)
{
    if (s.size() < 2 || s.size() > 3)
        return false;
    char col = toupper(s[0]);
    if (col < 'A' || col > 'J')
        return false;
    int c = col - 'A';
    int row = stoi(s.substr(1)) - 1;
    if (row < 0 || row >= ROWS)
        return false;
    idx = row * COLS + c;
    return true;
}

int main()
{
    Adversary adv;
    int heads = 0;
    vector<string> hits;
    vector<vector<char>> display(ROWS, vector<char>(COLS, '.'));
    while (heads < 3)
    {
        cout << "请输入坐标 (如 A1, J10): ";
        string s;
        cin >> s;
        int idx;
        if (!parseCoord(s, idx))
        {
            cout << "输入不合法！\n";
            continue;
        }
        int v = adv.respond(idx);
        int r = idx / COLS, c = idx % COLS;
        if(display[r][c] != '.')
        {
            cout << "炸过了！\n";
            continue;
        }
        if (v == 2)
            display[r][c] = 'H';
        else if (v == 1)
            display[r][c] = 'X';
        else
            display[r][c] = 'o';
        cout << "  ";
        for (int i = 0; i < 10; ++i)
            cout << (char)('A' + i) << " ";
        cout << endl;
        for (int i = 0; i < 10; ++i)
        {
            cout << setw(2) << i + 1 << " ";
            for (int j = 0; j < 10; ++j)
            {
                cout << display[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "反馈:" << v << endl;
        // cout << "剩余:" << adv.remaining() << "\n";
        if (v == 2)
        {
            heads++;
            hits.push_back(s);
        }
    }
    const auto &triples = adv.getTriples();
    const auto &placements = adv.getPlacements();
    int combo = -1;
    for (int i = 0; i < adv.getCurrent().count(); ++i)
    {
        for (int t = 0; t < triples.size(); ++t)
        {
            if (adv.getCurrent().test(t))
            {
                combo = t;
                break;
            }
        }
        if (combo != -1)
            break;
    }
    if (combo >= 0)
    {
        vector<vector<char>> grid(ROWS, vector<char>(COLS, '.'));
        for (int pi : triples[combo])
        {
            int h = placements[pi].headIdx;
            int hr = h / COLS, hc = h % COLS;
            grid[hr][hc] = 'H';
            for (int i = 0; i < TOTAL; i++)
                if (placements[pi].occupancy.test(i) && i != h)
                {
                    int r = i / COLS, c = i % COLS;
                    grid[r][c] = 'X';
                }
        }
        cout << "\n最终布局：\n";
        cout << "  A B C D E F G H I J\n";
        for (int r = 0; r < ROWS; r++)
        {
            cout << setw(2) << r + 1 << " ";
            for (int c = 0; c < COLS; c++)
                cout << grid[r][c] << " ";
            cout << "\n";
        }
    }
    cout << "游戏结束！\n";
    return 0;
}
