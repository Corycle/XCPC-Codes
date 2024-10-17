#include <bits/stdc++.h>
using namespace std;
const int maxn=2005;
char s[23333];
int fuck[maxn][maxn];
int A[maxn];
int B[maxn];
int C[maxn];
int num[maxn];

bitset<(int)(2e6+6)> qq;


class ufs
{
public:
int fa[maxn];
ufs()
{
    for(int i=1;i<maxn;++i)
    {
        fa[i]=i;
    }
}
int find(int x)
{
    return (fa[x]==x?x:fa[x]=find(fa[x]));
}
bool find(int a,int b)
{
    return find(a)==find(b);
}
void merge(int a,int b)
{
    a=find(a);
    b=find(b);
    fa[a]=b;
}
};

bitset<maxn> bs[maxn];

int n,l,q;

void addedge(int x,int y)
{
    //cout<<"add "<<x<<" "<<y<<endl;
    for(int i=1;i<=n;++i)
    {
        if(bs[i][x])
        {
            bs[i] |= bs[y];
        }
    }

    for(int i=1;i<=n;++i)
    {
        if(bs[y][i])
        {
            bs[y] |= bs[i];
        }
    }

    for(int i=1;i<=n;++i)
    {
        if(bs[i][x])
        {
            bs[i] |= bs[y];
        }
    }
}

void mian()
{
    cin>>n>>l>>q;
    ufs T;
    for(int i=1;i<=n;++i)
    {
        bs[i] ^= bs[i];
        bs[i][i] = 1;
    }
    for(int i=1;i<=l;++i)
    {
        cin>>s;
        memset(num,0,sizeof num);
        int numberof2=0;
        int shit;
        for(int j=0;j<n*2;j+=2)
        {
            fuck[i][j/2+1] = (s[j]-48)*50 + (s[j+1]-48);
            num[fuck[i][j/2+1]]++;
            if(num[fuck[i][j/2+1]]>=2)
            {
                numberof2++;
                shit = fuck[i][j/2+1];
            }
        }
        if(numberof2 > 1)
        {
            A[i] = -2;
        }
        else if(numberof2==0)
        {
            A[i] = -1;
        }
        else
        {
            A[i]=0;
            int orz = 0;
            for(int j=1;j<=n;++j)
            {
                if(num[j]==0)
                {
                    orz = j;
                }
            }
            for(int j=1;j<=n;++j)
            {
                if(fuck[i][j]==shit)
                {
                    if(A[i])
                    {
                        C[i] = j;
                    }
                    else
                    {
                        A[i] = j;
                        B[i] = orz;
                    }
                }
            }
        }
    }


    vector<pair<pair<int,int> ,int > > qry[maxn];


    for(int i=1;i<=q;++i)
    {
        cin>>s;
        int a = (s[0]-48)*50 + (s[1]-48);
        int b = (s[2]-48)*50 + (s[3]-48);
        int c = (s[4]-48)*50 + (s[5]-48);

        qry[c].emplace_back(make_pair(a,b),i);
    }


    for(int i=0;i<=l;++i)
    {
        if(A[i] == -1)
        {
            for(int j=1;j<=n;++j)
            {
                int k = fuck[i][j];
                if(!T.find(j,k))
                {
                    T.merge(j,k);
                    addedge(j,k);
                    addedge(k,j);
                }
            }
        }
        else if(A[i] >= 0)
        {
            addedge(A[i],B[i]);
            addedge(C[i],B[i]);
        }

        for(auto j : qry[i])
        {
            qq[j.second] = bs[j.first.first][j.first.second];
        }
    }

    for(int i=1;i<=q;++i) putchar(qq[i]+'0');

    putchar('\n');


}
int main()
{
    //freopen("shit.in","r",stdin);
    //freopen("shit.out","w",stdout);
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        mian();
    }
    return 0;
}