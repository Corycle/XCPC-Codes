#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e6+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,ans,flag;
int a[N],b[N],f[N],g[N],tag[N],vis[N],pre[N],sum[N];
vector<int>G[N];
void DFS1(int x){
	vis[x]=1;
	for(auto y:G[x]){
		if(y==pre[x])continue;
		if(!vis[y]){
			pre[y]=x;
			DFS1(y);
		}
		else if(!flag){
			flag=1;
			int k=x;
			tag[x]=1;
			b[++m]=x;
			while(k!=y){
				k=pre[k];
				tag[k]=1;
				b[++m]=k;
			}
		}
	}
}
void DFS2(int x,int fa){
	int m1=0,m2=0;
	for(auto y:G[x]){
		if(y==fa||tag[y])continue;
		DFS2(y,x);
		if(m1<f[y]){m2=m1;m1=f[y];}
		else if(m2<f[y])m2=f[y];
	}
	ans=max(ans,m1+m2+a[x]);
	f[x]=m1+a[x];
	g[x]=m1+m2;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		int x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	DFS1(1);
	for(int i=1;i<=m;i++){
		DFS2(b[i],0);
		f[b[i]]-=a[b[i]];
		sum[i]=sum[i-1]+a[b[i]];
	}
	int m1=-inf,m2=-inf;
	for(int i=1;i<=m;i++){
		/*
			case 1: sum[i]-sum[j-1]+f[b[i]]+f[b[j]] = (f[b[i]]+sum[i])+(f[b[j]]-sum[j-1])
			case 2: sum[m]-sum[i-1]+sum[j]+f[b[i]]+f[b[j]] = sum[m]+(f[b[i]]-sum[i-1])+(f[b[j]]+sum[j])
		*/
		ans=max(ans,g[b[i]]+sum[m]);
		ans=max(ans,f[b[i]]+sum[i]+m1);
		ans=max(ans,f[b[i]]-sum[i-1]+sum[m]+m2);
		m1=max(m1,f[b[i]]-sum[i-1]);
		m2=max(m2,f[b[i]]+sum[i]);
	}
	printf("%d\n",ans);
	return 0;
}
/*
9
1 0 1 0 0 1 1 0 1
2 8
2 9
2 5
1 5
1 3
1 4
4 5
4 6
6 7
*/
