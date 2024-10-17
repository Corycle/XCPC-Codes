#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const ll MAXN=1e18;
const ll INF=1e13;
const int N=1e5+5;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
ll Flow,Cost,dis[N];
int n,m,tot,cnt,h[N],vis[N],Col[N],id[N][2];
struct edge{int to,next,flow;ll cost;}d[N];
void Add(int x,int y,int f,ll c){
    // cout<<"Add: "<<x<<" "<<y<<" "<<f<<" "<<c<<endl;
    d[++cnt]=(edge){y,h[x],f,c};h[x]=cnt;
    d[++cnt]=(edge){x,h[y],0,-c};h[y]=cnt;
}
void Clear(){
    for(int i=1;i<=tot;i++)h[i]=0;
    Flow=Cost=0;
    tot=0;
    cnt=1;
}
bool SPFA(int s,int t){
    for(int i=1;i<=tot;i++){dis[i]=-MAXN;vis[i]=0;}
    queue<int>q;q.push(s);dis[s]=0;
    while(!q.empty()){
        int x=q.front();q.pop();vis[x]=0;
        for(int i=h[x];i;i=d[i].next){
            int y=d[i].to;
            if(d[i].flow&&dis[y]<dis[x]+d[i].cost){
                dis[y]=dis[x]+d[i].cost;
                if(!vis[y]){vis[y]=1;q.push(y);}
            }
        }
    }
    return dis[t]!=-MAXN;
}
int DFS(int x,int maxn,int t){
    if(x==t||!maxn)return maxn;
    int ans=0;vis[x]=1;
    for(int i=h[x];i;i=d[i].next){
        int y=d[i].to;
        if(d[i].flow&&!vis[y]&&dis[y]==dis[x]+d[i].cost){
            int dlt=DFS(y,min(maxn,d[i].flow),t);
            if(!dlt)dis[y]=-MAXN;
            d[i].flow-=dlt;
            d[i^1].flow+=dlt;
            ans+=dlt;maxn-=dlt;
            if(!maxn)return ans;
        }
    }
    return ans;
}
void ZKW(int s,int t){
    while(SPFA(s,t)){
        int flow=DFS(s,inf,t);
        // cout<<flow<<" "<<flow*dis[t]<<endl;
        Flow+=flow;
        Cost+=flow*dis[t];
    }
}
int main(){
    int T=read();
    while(T--){
        Clear();
        n=read();m=read();
        int S=++tot,T=++tot;
        int sum=0;
        for(int i=1;i<=m;i++){
            Col[i]=++tot;
            int l=read();
            sum+=l;
            Add(S,Col[i],l,0);
        }
        for(int i=1;i<=n*2;i++){
            id[i][0]=++tot;
            id[i][1]=++tot;
            int c=read();
            Add(Col[c],id[i][0],1,0);
            Add(S,id[i][0],1,-INF);
        }
        for(int i=1;i<=n*2;i++){
            int v=read();
            Add(id[i][0],id[i][1],1,v);
        }
        for(int i=1;i<=n;i++){
            int x=++tot;
            for(int j=1;j<=i*2-1;j++){
                Add(id[j][1],x,1,0);
            }
            Add(x,T,1,0);
        }
        if(sum>n){
            puts("-1");
            continue;
        }
        ZKW(S,T);
        Cost+=(n-sum)*INF;
        if(Flow!=n||Cost<0){
            puts("-1");
            continue;
        }
        printf("%lld\n",Cost);
    }
    return 0;
}