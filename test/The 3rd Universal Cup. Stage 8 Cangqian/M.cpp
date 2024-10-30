#include <bits/stdc++.h>
using namespace std;
#define int __int128
const long long maxn=2e6+5;
int f[maxn];
void print(int x)
{
    if(x==0) return;
    print(x/10);
    cout<<(long long)(x%10);
}
signed main()
{
    ios::sync_with_stdio(0);
    long long n,a,b;
    cin>>n>>a>>b;
    for(int i=2;i<maxn;++i)
    {
        f[i] = f[i-1]+(i/2+1)*(i/2);
        if(i%2 == 0) f[i]= f[i]-(i)/2;
    }
    int ans=0;
    for(int i=1;i<=n;++i) ans=ans+i*(n+1-i);
    ans = ans + f[n];
    int x = a-1;
    int y= b;
    ans = ans - b*(a-b+1);
    for(int i=1;i<=(n-a);++i)
    {
        int l = max((long long)b+1,(long long)i+1);
        int r = min((long long)(b+i),(long long)a+1);
        if(r-l+1<0)continue;
        ans = ans - (r-l+1);
    }
    if(ans==0) cout<<0;
    else print(ans);
    return 0;
}