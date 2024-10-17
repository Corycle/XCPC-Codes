/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=4e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,cnt;
int h[N],a[N],vis[N],pre[N],dep[N],fa[N],sum[N];
struct edge{int to,next,id;}d[N*2];
void Add(int x,int y,int z){d[++cnt]=(edge){y,h[x],z};h[x]=cnt;}
int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
void Merge(int x,int y){x=Find(x);y=Find(y);if(x==y)return;fa[x]=y;sum[y]+=sum[x];}
void DFS(int x){
	vis[x]=1;
	for(int i=h[x];i;i=d[i].next){
		int y=d[i].to;
		if(vis[y])continue;
		a[d[i].id]=1;
		pre[y]=d[i].id;
		dep[y]=dep[x]+1;
		DFS(y);
	}
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int Case=read();
	while(Case--){
		n=read();m=read();cnt=0;
		for(int i=1;i<=n;i++)h[i]=vis[i]=pre[i]=dep[i]=0;
		for(int i=1;i<=m;i++){int x=read(),y=read();Add(x,y,i);Add(y,x,i);a[i]=0;}
		if(m==n-1){
			for(int i=1;i<=m;i++)printf("0");
			puts("");
		}
		else if(m<=n+1){
			DFS(1);
			for(int i=1;i<=m;i++)printf("%d",a[i]);
			puts("");
		}
		else{
			DFS(1);
			for(int i=1;i<=n;i++){fa[i]=i;sum[i]=1;}
			for(int x=1;x<=n;x++){
				for(int i=h[x];i;i=d[i].next){
					if(!a[d[i].id])Merge(x,d[i].to);
				}
			}
			int x=0,y=0;
//			for(int i=1;i<=n;i++)cout<<Find(i)<<" ";cout<<endl;
//			for(int i=1;i<=n;i++)cout<<fa[i]<<" ";cout<<endl;
//			for(int i=1;i<=n;i++)cout<<sum[i]<<" ";cout<<endl;
			for(int i=1;i<=n;i++){
				if(sum[Find(i)]==3){
					if(!x)x=i;
					else if(!y){y=i;break;}
				}
			}
//			cout<<x<<" "<<y<<endl;
			if(x&&y){
				if(dep[x]<=dep[y])a[pre[y]]=0;
				else a[pre[x]]=0;
				for(int i=h[x];i;i=d[i].next){
					if(y==d[i].to){a[d[i].id]=1;break;}
				}
			}
			for(int i=1;i<=m;i++)printf("%d",a[i]);
			puts("");
		}
	}
	return 0;
}
/*
1
5 7
1 2
2 3
3 1
1 5
2 5
2 4
3 4
*/
