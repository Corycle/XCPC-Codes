#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define pii pair<int,int>
#define mp make_pair
#define fst first
#define scd second
using namespace std;
const int N=5e5+5;
const int inf=0x3f3f3f3f;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
vector<int>G[N];
int n,m,cnt,tot;
int h[N],fa[N],sum[N],son[N],top[N],dep[N],pos[N],id[N],dis[N],vis[N];
struct edge{int to,next,dist;}d[N*10];
void Add(int x,int y,int z){
	d[++cnt]=(edge){y,h[x],z};h[x]=cnt;
//	cout<<"Add: "<<x<<" "<<y<<endl;
}
void DFS1(int x,int depth){
	dep[x]=depth;sum[x]=1;
	for(auto y:G[x]){
		DFS1(y,depth+1);
		sum[x]+=sum[y];
		if(sum[son[x]]<sum[y])son[x]=y;
	}
}
void DFS2(int x,int tp){
	top[x]=tp;pos[id[x]=++tot]=x;
	if(son[x])DFS2(son[x],tp);
	for(auto y:G[x]){
		if(y==son[x])continue;
		DFS2(y,y);
	}
}
struct Segment_Tree{
	int ID[N];
	void Build(int p,int l,int r){
		ID[p]=++tot;
		if(l==r){
			Add(ID[p],l,0);
			return;
		}
		int mid=(l+r)>>1;
		Build(lson);Build(rson);
		Add(ID[p],ID[p<<1],0);
		Add(ID[p],ID[p<<1|1],0);
	}
	void Update(int u,int x,int y,int p,int l,int r){
		if(y<l||x>r)return;
		if(x<=l&&r<=y){
			Add(u,ID[p],1);
			return;
		}
		int mid=(l+r)>>1;
		Update(u,x,y,lson);
		Update(u,x,y,rson);
	}
}tree;
void Addedge(int u,int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		tree.Update(id[u],id[top[x]],id[x],1,1,n);
		x=fa[top[x]];
	}
	if(id[x]>id[y])swap(x,y);
	tree.Update(id[u],id[x],id[y],1,1,n);
}
void Dijkstra(){
	priority_queue<pii,vector<pii>,greater<pii> >q;
	for(int i=1;i<=tot;i++)dis[i]=inf;
	q.push(mp(dis[1]=0,1));
	while(!q.empty()){
		int x=q.top().scd;q.pop();
		if(vis[x])continue;vis[x]=1;
		//cout<<x<<endl;
		for(int i=h[x];i;i=d[i].next){
			int y=d[i].to;
			if(dis[y]>dis[x]+d[i].dist){
				dis[y]=dis[x]+d[i].dist;
				q.push(mp(dis[y],y));
			}
		}
	}
}
int main(){
	n=read();m=read();
	for(int i=2;i<=n;i++)G[fa[i]=read()].push_back(i);
	DFS1(1,1);DFS2(1,1);
//	for(int i=1;i<=n;i++)cout<<top[i]<<" ";cout<<endl;
//	for(int i=1;i<=n;i++)cout<<id[i]<<" ";cout<<endl;
	tree.Build(1,1,n);
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		Addedge(x,x,y);
		Addedge(y,x,y);
	}
	Dijkstra();
	for(int i=2;i<=n;i++)printf("%d ",dis[id[i]]==inf?-1:dis[id[i]]);
	return 0;
}
