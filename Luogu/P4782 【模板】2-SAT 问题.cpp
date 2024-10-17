/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e6+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,cnt,tot,top,scc;
int h[N],b[N],st[N],dfn[N],low[N],vis[N];
struct edge{int to,next;}d[N];
void Add(int x,int y){d[++cnt]=(edge){y,h[x]};h[x]=cnt;}
void DFS(int x){
	dfn[x]=low[x]=++tot;st[++top]=x;vis[x]=1;
	for(int i=h[x];i;i=d[i].next){
		int y=d[i].to;
		if(!dfn[y]){
			DFS(y);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y])low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x]){
		int k=0;scc++;
		do{k=st[top--];b[k]=scc;vis[k]=0;}while(k!=x);
	}
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=m;i++){
		int x=read(),t1=read(),y=read(),t2=read();
		Add(x+(t1^1)*n,y+t2*n);
		Add(y+(t2^1)*n,x+t1*n);
	}
	for(int i=1;i<=n*2;i++)if(!dfn[i])DFS(i);
	for(int i=1;i<=n;i++)if(b[i]==b[i+n]){puts("IMPOSSIBLE");return 0;}
	puts("POSSIBLE");
	for(int i=1;i<=n;i++)printf("%d ",b[i]>b[i+n]);
	return 0;
}
