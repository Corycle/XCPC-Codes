#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
const int Mod=998244353;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m;
ll a[N],sum[N],ans1,ans2,num[N],fac[N];
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	fac[0]=fac[1]=1;
	for(int i=1;i<=n;i++){
		fac[i]=1ll*fac[i-1]*i%Mod;
		sum[i]=sum[i-1]+a[i];
		ans1+=a[i]*i-sum[i];
		if(i!=1&&a[i]==a[i-1])num[i]=num[i-1]+1;
		else num[i]=1;
	}
	ans2=1;
	for(int i=1;i<=n;i++)if(a[i]!=a[i+1]||i==n)ans2=ans2*fac[num[i]]%Mod;
	if(a[1]!=a[n])ans2=2*ans2%Mod;
	printf("%lld %lld\n",ans1,ans2);
	return 0;
}
