#include <bits/stdc++.h>
using namespace std;
#define int long long
void mian()
{
    int n,m;
    cin>>n>>m;
    if(__gcd(n,m)==1)
    {
        cout<<"Yes\n";
        for(int i=1;i<=n;++i) cout<<(1+i*m)%(n*m)<<" ";
        cout<<"\n";
        for(int i=1;i<=m;++i) cout<<(1+i*n)%(n*m)<<" ";
        cout<<"\n";
    }
    else
    {
        cout<<"No\n";
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        mian();
    }
}