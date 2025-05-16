#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
const int N=5e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,ans,sum,cnt[N],fac[N],inv[N];
int Pow(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%Mod;
		x=1ll*x*x%Mod;
		y>>=1;
	}
	return ans;
}
int Inv(int x){
	return Pow(x,Mod-2);
}
void Prepare(){
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2;i<N;i++)fac[i]=1ll*fac[i-1]*i%Mod;
	for(int i=2;i<N;i++)inv[i]=1ll*inv[Mod%i]*(Mod-Mod/i)%Mod;
	for(int i=2;i<N;i++)inv[i]=1ll*inv[i-1]*inv[i]%Mod;
}
int C(int n,int m){return 1ll*fac[n]*inv[m]%Mod*inv[n-m]%Mod;}
int main(){
	Prepare();
	n=read();sum=fac[n-2];
	for(int i=1;i<=n;i++)cnt[read()]++;
	for(int i=1;i<N;i++)sum=1ll*sum*inv[cnt[i]]%Mod;
	for(int i=1;i<N;i++){
		if((n-2)%i==0&&cnt[i]&&cnt[(n-2)/i]){
			if(i!=(n-2)/i){
				int res=1ll*sum*fac[cnt[i]]%Mod*fac[cnt[(n-2)/i]]%Mod;
				res=1ll*res*inv[cnt[i]-1]%Mod*inv[cnt[(n-2)/i]-1]%Mod;
				ans=(ans+res)%Mod;
			}
			else{
				int res=1ll*sum*fac[cnt[i]]%Mod*inv[cnt[i]-2]%Mod;
				ans=(ans+res)%Mod;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
