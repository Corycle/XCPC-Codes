/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fst first
#define scd second
#define pii pair<int,int>
using namespace std;
const ll INF=1e18;
const int inf=0x3f3f3f3f;
const int N=3005;
const int M=20005;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,cnt;
int h[N],deg[N];
ll dis[N][N][2];
struct edge{int to,next,dist;}d[M];
void Add(int x,int y,int z){d[++cnt]=(edge){y,h[x],z};h[x]=cnt;}
void Solve(int s,ll dist[][2]){
    for(int x=1;x<=n;x++){
        for(int i=h[x];i;i=d[i].next)deg[d[i].to]++;
        dist[x][0]=dist[x][1]=INF;
    }
    queue<int>q;
    for(int i=1;i<=n;i++)if(!deg[i])q.push(i);
    dist[s][0]=0;
    while(!q.empty()){
        int x=q.front();q.pop();
        for(int i=h[x];i;i=d[i].next){
            int y=d[i].to;
            ll w=dist[x][0]+d[i].dist;
            if(dist[y][0]>w){
                dist[y][1]=dist[y][0];
                dist[y][0]=w;
            }
            else dist[y][1]=min(dist[y][1],w);
            if(!(--deg[y]))q.push(y);
        }
    }
}
int main(){
	// freopen("graph20.in","r",stdin);
	// freopen("graph20.out","w",stdout);
    // double S=clock();
	n=read();m=read();
    for(int i=1;i<=m;i++){int x=read(),y=read();Add(x,y,read());}
    for(int i=1;i<=n;i++)Solve(i,dis[i]);
    ll ans=INF;
    for(int x=1;x<=n;x++){
        for(int y=1;y<=n;y++){
            ans=min(ans,dis[1][x][0]+dis[x][y][0]+dis[x][y][1]+dis[y][n][0]);
        }
    }
    printf("%lld\n",ans);
    // cerr<<clock()-S<<endl;
	return 0;
}
