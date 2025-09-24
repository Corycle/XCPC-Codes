#include<bits/stdc++.h>
#define pii pair<int,int>
#define fst first
#define scd second
#define mp make_pair
using namespace std;
const int N=2e5+5;
const int inf=0x3f3f3f3f;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,V,T,vis[N];
pii dis[N];
vector<pii>G[N];
struct Node{
	int x;
	pii dis;
	friend bool operator<(Node A,Node B){
		return A.dis>B.dis;
	}
};
void Solve(int s){
	for(int i=1;i<=n;i++){
		dis[i]=mp(inf,inf);
	}
	priority_queue<Node>q;
	dis[s]=mp(1,0);
	q.push((Node){s,mp(1,0)});
	while(q.size()){
		int x=q.top().x;q.pop();
		if(vis[x])continue;vis[x]=1;
		for(auto e:G[x]){
			int y=e.fst,w=e.scd;
			pii dist=dis[x];
			if(dist.scd+w>V)dist=mp(dist.fst+1,w);
			else dist=mp(dist.fst,dist.scd+w);
			if(dis[y]>dist){
				dis[y]=dist;
				q.push((Node){y,dist});
			}
		}
	}
}
int main(){
	n=read();m=read();V=read();T=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		G[x].push_back(mp(y,z));
		G[y].push_back(mp(x,z));
	}
	Solve(T);
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			printf("-1 ");
			continue;
		}
		int ans=dis[i].fst;
		printf("%d ",ans);
	}
	return 0;
}
