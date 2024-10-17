#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Mod=1e9+7;
const int N=3e5+5;
const int M=63;
ll read(){
    ll s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n;
ll a[N],sum[N],f[N],Sum[M][2];
int main(){
    n=read();
    f[0]=1;
    for(int i=0;i<M;i++)Sum[i][0]=1;
    for(int i=1;i<=n;i++){
        a[i]=read();
        sum[i]=sum[i-1]^a[i];
        for(int j=0;j<M;j++){
            f[i]=(f[i]+(1ll<<j)%Mod*Sum[j][!((sum[i]>>j)&1)])%Mod;
        }
        for(int j=0;j<M;j++){
            Sum[j][(sum[i]>>j)&1]=(Sum[j][(sum[i]>>j)&1]+f[i])%Mod;
        }
    }
    printf("%lld\n",f[n]);
    return 0;
}