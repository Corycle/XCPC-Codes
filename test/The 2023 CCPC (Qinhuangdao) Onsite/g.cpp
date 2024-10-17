#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+5;
int a[maxn],b[maxn];
int Abs(int x)
{
    if(x<0) return -x;
    return x;
}
signed main()
{
    ios::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;++i)
    {
        cin>>b[i];
    }
    int ans=0;
    for(int i=2;i<=n;++i)
    {
        ans=ans+Abs(a[i]-a[i-1]);
    }
    for(int i=2;i<=m;++i)
    {
        ans=ans+Abs(b[i]-b[i-1]);
    }
    cout<<ans;
    return 0;
}