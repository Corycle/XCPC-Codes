/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int Inv2=500000004;
const int Inv6=166666668;
const int Mod=1e9+7;
const int N=1e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,cnt,mu[N],f[N],prime[N],vis[N];
int mod(int x){return x>=Mod?x-Mod:x;}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int Pow(int x,int y){int ans=1;while(y){if(y&1)ans=1ll*ans*x%Mod;x=1ll*x*x%Mod;y>>=1;}return ans;}
void Prepare(int n){
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){prime[++cnt]=i;mu[i]=-1;}
		for(int j=1;j<=cnt&&1ll*i*prime[j]<=n;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j])mu[i*prime[j]]=-mu[i];
			else{mu[i*prime[j]]=0;break;}
		}
		mu[i]=mod(mu[i]+Mod);
	}
	for(int i=1;i<=n;i++){
		int k=1ll*i*Pow(gcd(i,n),Mod-2)%Mod;
		for(int j=i;j<=n;j+=i)f[j]=mod(f[j]+1ll*k*mu[j/i]%Mod);
	}
}
int Sn1(int n){return 1ll*n*(n+1)%Mod*Inv2%Mod;}
int Sn2(int n){return 1ll*n*(n+1)%Mod*(2*n+1)%Mod*Inv6%Mod;}
int G(int T){
	int a=(n-2)/T,b=(n-1)/T;
	int Sn=1ll*n*mod(1ll*a*b%Mod-Sn1(a)+Mod)%Mod;
	int Sy=mod(1ll*a*Sn1(b)%Mod-1ll*mod(Sn1(a)+Sn2(a))*Inv2%Mod+Mod);
	return mod(Sn-1ll*Sy*T%Mod+Mod);
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();Prepare(n);
	int Ans=0;
	for(int i=1;i<=n;i++)Ans=mod(Ans+1ll*f[i]*G(i)%Mod);
	printf("%d\n",Ans);
	return 0;
}
