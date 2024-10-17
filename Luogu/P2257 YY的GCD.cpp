/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e7+5;
const int M=1e6+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
ll sum[N];
bool vis[N];
int n,m,cnt,prime[M],mu[N];
void Prepare(){
	vis[1]=1;mu[1]=1;sum[1]=0;
	for(int i=1;i<N;i++){
		if(!vis[i]){prime[++cnt]=i;mu[i]=-1;sum[i]=1;}
		for(int j=1;j<=cnt&&1ll*i*prime[j]<N;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]){mu[i*prime[j]]=-mu[i];sum[i*prime[j]]=-sum[i]+mu[i];}
			else{mu[i*prime[j]]=0;sum[i*prime[j]]=mu[i];break;}
		}
		sum[i]+=sum[i-1];
	}
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	Prepare();
	int num=read();
	while(num--){
		n=read();m=read();
		ll Ans=0;
		for(int i=1,j=0;i<=min(n,m);i=j+1){
			j=min(n/(n/i),m/(m/i));
			Ans+=1ll*(sum[j]-sum[i-1])*(n/i)*(m/i);
		}
		printf("%lld\n",Ans);
	}
	return 0;
}
