/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=3e5+5;
const int M=20;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
vector<int>G[N];
int n,m,cnt,tot,num,top,Root;
int a[N],h[N],st[N],id[N],sum[N],dfn[N],dep[N],Ans[N],p[N][M],Sum[N];
struct Node{
	int dis,pos;
	friend bool operator<(Node x,Node y){return x.dis!=y.dis?x.dis<y.dis:x.pos<y.pos;}
}F[N];
struct edge{int to,next;}d[N*2];
bool cmp(int x,int y){return dfn[x]<dfn[y];}
void Add(int x,int y){d[++cnt]=(edge){y,h[x]};h[x]=cnt;}
void DFS(int x,int fa){
	dfn[x]=++tot;sum[x]=1;p[x][0]=fa;dep[x]=dep[fa]+1;
	for(int i=1,k=(int)(log(dep[x])/log(2));i<=k;i++)p[x][i]=p[p[x][i-1]][i-1];
	for(int i=h[x];i;i=d[i].next){int y=d[i].to;if(y!=fa){DFS(y,x);sum[x]+=sum[y];}}
}
int LCA(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=(int)(log(dep[x])/log(2));i>=0;i--)if(dep[x]-(1<<i)>=dep[y])x=p[x][i];
	if(x==y)return x;
	for(int i=(int)(log(dep[x])/log(2));i>=0;i--)if(p[x][i]!=p[y][i]){x=p[x][i];y=p[y][i];}
	return p[x][0];
}
int Dist(int x,int y){return dep[x]+dep[y]-dep[LCA(x,y)]*2;}
void Build(){
	sort(a+1,a+num+1,cmp);st[top=1]=a[1];
	for(int i=2;i<=num;i++){
		int lca=LCA(a[i],st[top]);
		while(top>1&&dep[st[top-1]]>=dep[lca]){G[st[top-1]].push_back(st[top]);top--;}
		if(st[top]!=lca){G[lca].push_back(st[top]);st[top]=lca;}
		st[++top]=a[i];
	}
	while(top>1){G[st[top-1]].push_back(st[top]);top--;}
	Root=st[top];
}
void Solve(int x,int y){
	int px=F[x].pos,py=F[y].pos,pre=y;
	for(int i=(int)(log(dep[y])/log(2));i>=0;i--){
		if(dep[y]-(1<<i)>dep[x]){
			int z=p[y][i],dx=Dist(px,z),dy=Dist(py,z);
			if(dy<dx||(dy==dx&&py<px)){Ans[id[py]]+=sum[z]-sum[y];y=z;}
		}
		if(dep[pre]-(1<<i)>dep[x])pre=p[pre][i];
	}
	Ans[id[px]]+=sum[pre]-sum[y];
	Sum[x]-=sum[pre];
}
void DFS1(int x){
	F[x]=id[x]?(Node){0,x}:(Node){inf,0};Sum[x]=sum[x];
	for(auto y:G[x]){
		DFS1(y);
		int dis=F[y].dis+dep[y]-dep[x];
		F[x]=min(F[x],(Node){dis,F[y].pos});
	}
}
void DFS2(int x,int pos){
	if(pos)F[x]=min(F[x],(Node){Dist(x,pos),pos});
	for(auto y:G[x]){DFS2(y,F[x].pos);Solve(x,y);}
	Ans[id[F[x].pos]]+=Sum[x];
}
void Clear(int x){
	for(auto y:G[x])Clear(y);
	G[x].clear();id[x]=0;
}
int main(){
//	freopen("P3233_1.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();
	for(int i=1;i<n;i++){int x=read(),y=read();Add(x,y);Add(y,x);}
	DFS(1,0);
	m=read();
	while(m--){
		num=read();
		for(int i=1;i<=num;i++)id[a[i]=read()]=i;
		Build();DFS1(Root);DFS2(Root,0);
		Ans[id[F[Root].pos]]+=n-sum[Root];
		for(int i=1;i<=num;i++)printf("%d ",Ans[i]);printf("\n");
		for(int i=1;i<=num;i++)Ans[i]=0;
		Clear(Root);
	}
	return 0;
}
