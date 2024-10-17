/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fst first
#define scd second
#define mp make_pair
using namespace std;
const int inf=0x3f3f3f3f;
const int M=1e5+5;
const int N=1005;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,cnt,Ans;
int h[N],dis[N],vis[N];
struct Edge{int x,y,z;}e[M];
struct edge{int to,next,dist;}d[M];
void Add(int x,int y,int z){d[++cnt]={y,h[x],z};h[x]=cnt;}
void Dijkstra(){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pii,vector<pii>,greater<pii> >q;
	dis[1]=0;q.push(mp(0,1));
	while(!q.empty()){
		int x=q.top().scd;q.pop();
		if(vis[x])continue;vis[x]=1;
		for(int i=h[x];i;i=d[i].next){
			int y=d[i].to;
			if(dis[y]>dis[x]+d[i].dist){
				dis[y]=dis[x]+d[i].dist;
				q.push(mp(dis[y],y));
			}
		}
	}
	for(int i=1;i<=n;i++)Ans+=dis[i];
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=m;i++){e[i].x=read();e[i].y=read();e[i].z=read();}
	for(int i=1;i<=m;i++)Add(e[i].x,e[i].y,e[i].z);
	Dijkstra();
	cnt=0;memset(h,0,sizeof(h));
	for(int i=1;i<=m;i++)Add(e[i].y,e[i].x,e[i].z);
	Dijkstra();
	printf("%d\n",Ans);
	return 0;
}
