/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int Mod=998244353;
const int Phi=998244352;
const int N=6e5+5;
const int G=3;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,fac[N],inv[N],f[N];
int mod(int x){return x>=Mod?x-Mod:x;}
void Prepare(){
	fac[0]=fac[1]=inv[0]=inv[1]=f[0]=f[1]=1;
	for(int i=2;i<N;i++)fac[i]=1ll*fac[i-1]*i%Mod;
	for(int i=2;i<N;i++)inv[i]=1ll*inv[Mod%i]*(Mod-Mod/i)%Mod;
	for(int i=2;i<N;i++)inv[i]=1ll*inv[i-1]*inv[i]%Mod;
	for(int i=2;i<N;i++)f[i]=mod(f[i-1]+1ll*f[i-2]*(i-1)%Mod);
}
int C(int n,int m){return 1ll*fac[n]*inv[m]%Mod*inv[n-m]%Mod;}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	Prepare();
	int Case=read();
	while(Case--){
		n=read();
		int Ans=0;
		for(int i=0;4*i<=n;i++){
			Ans=mod(Ans+1ll*fac[n-2*i]*inv[i]%Mod*inv[n-4*i]%Mod*f[n-4*i]%Mod);
		}
		printf("%d\n",Ans);
	}
	return 0;
}
