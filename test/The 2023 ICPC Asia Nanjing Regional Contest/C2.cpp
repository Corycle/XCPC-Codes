#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int p,m;
    cin>>p>>m;
    int ans=0;
    for(int i=1;;i+=p)
    {
        if(__lg(i)>__lg(m)+3 && __lg(i)>__lg(p-1)+3)
        {
            break;
        }
        ans+=(int)((i^(p-1))<=m);
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        solve();
    }
    return 0;
}