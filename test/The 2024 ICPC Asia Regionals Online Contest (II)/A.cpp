#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
using tr = tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update>;
const int maxn=1e6+5;
int c[maxn];
map<string,set<pair<int,int> > > mp;
int x[maxn];
string team[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;++i)
    {
        cin>>c[i];
    }
    int fuck = c[1];
    for(int i=1;i<=k;++i)
    {
        fuck = min(fuck,c[i]);
    }
    tr t;
    for(int i=1;i<=n;++i)
    {
        int st;
        string name;
        cin>>st>>name;
        x[i]=st;
        team[i]=name;
        auto& tmp = mp[name];
        tmp.emplace(st,i);
        t.insert(make_pair(-st,i));
        if(tmp.size()>fuck)
        {
            auto tmpf = *(tmp.begin());
            tmp.erase(tmpf);
            tmpf.first = -tmpf.first;
            t.erase(tmpf);
        }
    }
    
    for(int i=1;i<=n;++i)
    {
        int fuck = (mp[team[i]].begin())->first;
        if(x[i]<fuck)
        {
            auto orz = *(mp[team[i]].begin());
            orz.first = -orz.first;
            auto o = make_pair(-x[i],-114514);
            t.erase(orz);
            t.insert(o);

            auto shit = t.order_of_key(o);

            shit++;

            cout<<shit<<"\n";

            t.erase(o);
            t.insert(orz);
        }
        else
        {
            auto orz = make_pair(-x[i],i);
            auto o = make_pair(-x[i],-114514);
            t.erase(orz);
            t.insert(o);

            auto shit = t.order_of_key(o);

            shit++;

            //for(auto i:t) cout<<i.first<<" "<<i.second<<endl;

            cout<<shit<<"\n";

            t.erase(o);
            t.insert(orz);
        }
    }

}