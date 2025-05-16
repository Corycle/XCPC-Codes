#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e5+5;
const int M=105;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int a[M][M],id[M][M];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m,tot,cnt=1,Flow,Cost;
int h[N],H[N],dis[N],vis[N];
struct edge{int to,next,flow,cost;}d[N*10];
void Add(int x,int y,int f,int c){
    d[++cnt]=(edge){y,h[x],f,c};h[x]=cnt;
    d[++cnt]=(edge){x,h[y],0,-c};h[y]=cnt;
}
bool SPFA(int s,int t){
	for(int i=1;i<=tot;i++){vis[i]=0;dis[i]=inf;}
	queue<int>q;q.push(s);dis[s]=0;
	while(q.size()){
		int x=q.front();q.pop();vis[x]=0;
		for(int i=h[x];i;i=d[i].next){
			int y=d[i].to;
			if(d[i].flow&&dis[y]>dis[x]+d[i].cost){
				dis[y]=dis[x]+d[i].cost;
				if(!vis[y]){vis[y]=1;q.push(y);}
			}
		}
	}
	return dis[t]!=inf;
}
int DFS(int x,int maxx,int t){
	int ans=0;
	if(x==t||!maxx)return maxx;
	vis[x]=1;
	for(int &i=H[x];i;i=d[i].next){
		int y=d[i].to;
		if(d[i].flow&&!vis[y]&&dis[y]==dis[x]+d[i].cost){
			int dlt=DFS(y,min(d[i].flow,maxx),t);
			if(!dlt)dis[y]=-inf;
			d[i].flow-=dlt;
			d[i^1].flow+=dlt;
			maxx-=dlt;ans+=dlt;
			if(!maxx)return ans;
		}
	}
	return ans;
}
void ZKW(int s,int t){
	Flow=Cost=0;
	while(SPFA(s,t)){
		for(int i=1;i<=tot;i++){H[i]=h[i];vis[i]=0;}
		int dlt=DFS(s,inf,t);Flow+=dlt;Cost+=dlt*dis[t];
	}
}
int main(){
    n=read();m=read();
    int S=++tot,T=++tot;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=read();
            id[i][j]=++tot;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if((i+j)&1){
                for(int k=0;k<4;k++){
                    int x=i+dx[k],y=j+dy[k];
                    if(x<1||x>n||y<1||y>m)continue;
                    Add(id[i][j],id[x][y],1,(a[i][j]!=a[x][y]));
                }
                Add(S,id[i][j],1,0);
            }
            else Add(id[i][j],T,1,0);
        }
    }
    ZKW(S,T);
    printf("%d\n",Cost);
    return 0;
}