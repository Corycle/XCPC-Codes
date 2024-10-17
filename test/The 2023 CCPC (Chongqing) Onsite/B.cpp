#include <bits/stdc++.h>
using namespace std;
#define int long long
int x=0,y=0;
map<pair<int,int>,int> mp;
int query(int xx,int yy)
{
    if(mp.find(make_pair(xx,yy))!=mp.end())
    {
        return mp[make_pair(xx,yy)];
    }
    int dx=xx-x;
    int dy=yy-y;
    x=xx;
    y=yy;
    cout<<dx<<" "<<dy<<"\n";
    cout.flush();
    int t;
    cin>>t;
    if(t==0)
    {
        exit(0);
    }
    mp[make_pair(xx,yy)] = t;
    return t;
}
signed main()
{
    cin>>mp[make_pair(0ll,0ll)];
    if(mp[make_pair(0ll,0ll)]==0) return 0;
    int X,Y;
    {
    int l=-1000,r=1000;
    while(l<r)
    {
        int t1 = query(l,0);
        int t2 = query(r,0);
        if(t1==t2)
        {
            l=(l+r)>>1ll;
            break;
        }
        if(t1<t2)
        {
            r=((l+r)>>1ll);
        }
        else
        {
            l=((l+r)>>1ll)+1;
        }
    }
    X = l;
    }
    {
    int l=-1000,r=1000;
    while(l<r)
    {
        int t1 = query(X,l);
        int t2 = query(X,r);
        if(t1==t2)
        {
            l=(l+r)>>1ll;
            break;
        }
        if(t1<t2)
        {
            r=((l+r)>>1ll);
        }
        else
        {
            l=((l+r)>>1ll)+1;
        }
    }
    Y = l;
    }

    query(X,Y);

    return 0;
}