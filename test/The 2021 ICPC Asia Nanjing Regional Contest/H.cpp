#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,cnt;
int h[N],b[N];
ll f[N],g[N],a[N],sum[N];
struct edge{int to,next;}d[N*2];
void Add(int x,int y){d[++cnt]=(edge){y,h[x]};h[x]=cnt;}
void DFS(int x,int fa){
	f[x]=a[x];sum[x]=0;
	for(int i=h[x];i;i=d[i].next){
		int y=d[i].to;
		if(y==fa)continue;
		DFS(y,x);
		f[x]+=f[y]-a[y];
		sum[x]+=a[y];
	}
	ll Max1=0,pos1=0,Max2=0,pos2=0;
	for(int i=h[x];i;i=d[i].next){
		int y=d[i].to;
		if(y==fa)continue;
		if(a[y]+g[y]-f[y]>=Max1){
			Max2=Max1;pos2=pos1;
			Max1=a[y]+g[y]-f[y];pos1=y;
		}
		else if(a[y]+g[y]-f[y]>=Max2){
			Max2=a[y]+g[y]-f[y];pos2=y;
		}
	}
	g[x]=f[x];
	ll Ans=f[x];
	for(int i=h[x];i;i=d[i].next){
		int y=d[i].to;
		if(y==fa)continue;
		Ans=max(Ans,f[x]+a[y]);
		if(b[y]==3){
			if(pos1&&pos1!=y)Ans=max(Ans,f[x]+a[y]+Max1);
			if(pos2&&pos2!=y)Ans=max(Ans,f[x]+a[y]+Max2);
		}
	}
	f[x]=Ans;
}
int main(){
	int T=read();
	while(T--){
		n=read();cnt=0;
		for(int i=1;i<=n;i++)h[i]=f[i]=g[i]=sum[i]=0;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		for(int i=1;i<n;i++){
			int x=read(),y=read();
			Add(x,y);Add(y,x);
		}
		DFS(1,0);
		printf("%lld\n",f[1]);
	}
    return 0;
}
