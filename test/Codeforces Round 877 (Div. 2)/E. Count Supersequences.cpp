/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int Mod=1e9+7;
const int N=2e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,K,a[N],inv[N];
int mod(int x){return x>=Mod?x-Mod:x;}
int Pow(int x,int y){int ans=1;while(y){if(y&1)ans=1ll*ans*x%Mod;x=1ll*x*x%Mod;y>>=1;}return ans;}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
    inv[0]=inv[1]=1;
    for(int i=2;i<N;i++)inv[i]=1ll*inv[Mod%i]*(Mod-Mod/i)%Mod;
	int T=read();
    while(T--){
        n=read();m=read();K=read();
        for(int i=1;i<=n;i++)a[i]=read();
        int ans=Pow(K,m),C=1;
        for(int i=0;i<n;i++){
            ans=mod(ans-1ll*C*Pow(K-1,m-i)%Mod+Mod);
            C=1ll*C*(m-i)%Mod*inv[i+1]%Mod;
        }
        printf("%d\n",ans);
    }
	return 0;
}
