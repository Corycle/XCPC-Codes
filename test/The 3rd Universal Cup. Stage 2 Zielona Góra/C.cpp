#include<bits/stdc++.h>
#define ll long long
#define inf 4000000009ll
using namespace std;
ll read(){
    ll s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
ll n,a[505][505],b[505][505];
void rotate(){
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) b[i][j]=a[i][j];
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) a[i][j]=b[j][n-i+1];
}
void update(ll &ans){
    ll m = n/2+1;
    ans = min(ans, a[m][m]);
    ll x = inf, y = inf;
    for(int i=1;i<=m;++i) x = min(x,a[m][i]);
    for(int i=n;i>=m;--i) y = min(y,a[m][i]);
    ans = min(ans, x+y);
    // cout<<"xy"<<x+y<<endl;
    ll f1 = inf, f2 = inf, f3 = inf, f4 = inf;
    for(int i=1;i<=m;++i) for(int j=1;j<=m;++j) f1 = min(f1, a[i][j]);
    for(int i=1;i<=m;++i) for(int j=n;j>=m;--j) f2 = min(f2, a[i][j]);
    for(int i=n;i>=m;--i) for(int j=1;j<=m;++j) f3 = min(f3, a[i][j]);
    for(int i=n;i>=m;--i) for(int j=n;j>=m;--j) f4 = min(f4, a[i][j]);
    ans = min(ans, f1+f3+y);
    ans = min(ans, f1+f2+f3+f4);
}
void work(){
    n=read();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            a[i][j]=read();
        }
    }
    ll ans = inf;
    for(int i=1;i<=4;++i){
        update(ans);
        // cout<<"ans: "<<ans<<endl;
        rotate();
        // {
        //     cout<<"DEBUG\n";
        //     for(int i=1;i<=n;++i){
        //         for(int j=1;j<=n;++j){
        //             cout<<a[i][j]<<' ';
        //         }
        //         cout<<endl;
        //     }
        //     cout<<"DEBUG\n";
        // }
    }
    printf("%lld\n",ans);
}
int main(){
    int T=read();
    while(T--) work();
}