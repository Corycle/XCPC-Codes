#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
const int M=105;
const int inf=0x3f3f3f3f;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,tot,K,cnt=1;
int h[N],dis[N],vis[N],pre[N],id[M][M][2];
struct edge{int to,next,flow,cost;}d[N];
void Add(int x,int y,int f,int c){
    d[++cnt]=(edge){y,h[x],f,c};h[x]=cnt;
    d[++cnt]=(edge){x,h[y],0,-c};h[y]=cnt;
}
bool SPFA(int s,int t){
    for(int i=1;i<=tot;i++){dis[i]=-inf;vis[i]=pre[i]=0;}
    queue<int>q;q.push(s);dis[s]=0;
    while(!q.empty()){
        int x=q.front();q.pop();vis[x]=0;
        for(int i=h[x];i;i=d[i].next){
            int y=d[i].to;
            if(d[i].flow&&dis[y]<dis[x]+d[i].cost){
                dis[y]=dis[x]+d[i].cost;pre[y]=i;
                if(!vis[y]){vis[y]=1;q.push(y);}
            }
        }
    }
    return dis[t]!=-inf;
}
int Flow,Cost,Ans;
void Adjust(int s,int t){
    int dlt=inf;
    for(int x=t;x!=s;x=d[pre[x]^1].to)dlt=min(dlt,d[pre[x]].flow);
    for(int x=t;x!=s;x=d[pre[x]^1].to){d[pre[x]].flow-=dlt;d[pre[x]^1].flow+=dlt;}
    Flow+=dlt;Cost+=dlt*dis[t];Ans=max(Ans,Cost);
}
void Edmonds_Karp(int s,int t){
    while(SPFA(s,t))Adjust(s,t);
}
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    n=read();m=read();K=read();
    int S=++tot,T=++tot;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            id[i][j][0]=++tot;
            id[i][j][1]=++tot;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int val=read();
            if(val==-1)continue;
            Add(id[i][j][0],id[i][j][1],1,val-1);
            for(int k=0;k<4;k++){
                int x=i+dx[k],y=j+dy[k];
                if(x<1||x>n||y<1||y>m)continue;
                Add(id[i][j][1],id[x][y][0],1,0);
            }
        }
    }
    for(int i=1;i<=K;i++){
        int x=read(),y=read();
        Add(S,id[x][y][0],1,100);
    }
    for(int i=1;i<=K;i++){
        int x=read(),y=read();
        Add(id[x][y][1],T,1,0);
    }
    Edmonds_Karp(S,T);
    printf("%d\n",Ans);
    return 0;
}