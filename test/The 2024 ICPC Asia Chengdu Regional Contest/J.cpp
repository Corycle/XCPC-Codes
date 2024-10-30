#include <bits/stdc++.h>
using namespace std;
#define int long long
void mian()
{
    int n,m,q;
    cin>>n>>m>>q;
    set<int> avail;
    map<int,set<int> >fuck;
    map<int,int> delta;
    map<int,int> mp;
    for(int i=1;i<=n;++i)
    {
        delta[i] = m;
    }
    for(int i=1;i<=q;++i)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int x;
            cin>>x;
            avail.clear();
            avail.insert(x);
        }
        else if(t==2)
        {
            int id,x;
            cin>>id>>x;
            if(!avail.count(x))
            {
                continue;
            }
            if(fuck[x].count(id))
            {
                continue;
            }
            fuck[x].insert(id);
            mp[id]=mp[id]+delta[x];
            delta[x]--;
        }
        else
        {
            int id,x;
            cin>>id>>x;
            if(!avail.count(x))
            {
                continue;
            }
            if(fuck[x].count(id))
            {
                continue;
            }
            fuck[x].insert(id);
        }
    }
    vector<pair<int,int> > vt;
    for(int i=1;i<=m;++i)
    {
        vt.emplace_back(-mp[i],i);
    }
    sort(vt.begin(),vt.end());
    for(auto i:vt)
    {
        cout<<i.second<<" "<<-i.first<<"\n";
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;++i) mian();
}