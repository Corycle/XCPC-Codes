#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;
const ll inf=1e18;
const int N=2e5+5;
const int M=20;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,fa[N],p[N][M],dep[N];
ll Max[2][N][M];
vector<pair<int,int> >G[N];
struct Edge{int x,y,w;}P[N*3];
bool cmp(Edge A,Edge B){return A.w<B.w;}
int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
void Clear(){
    for(int i=1;i<=n;i++){
        G[i].clear();
        dep[i]=0;
    }
}
void DFS(int x,int depth){
    dep[x]=depth;
    for(auto e:G[x]){
        int y=e.first,w=e.second;
        if(dep[y])continue;
        Max[w&1][y][0]=w;
        Max[!(w&1)][y][0]=-inf;
        p[y][0]=x;
        for(int i=1;i<M;i++){
            p[y][i]=p[p[y][i-1]][i-1];
            Max[0][y][i]=max(Max[0][y][i-1],Max[0][p[y][i-1]][i-1]);
            Max[1][y][i]=max(Max[1][y][i-1],Max[1][p[y][i-1]][i-1]);
        }
        DFS(y,depth+1);
    }
}
int LCA(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    for(int k=M-1;k>=0;k--)if(dep[x]-(1<<k)>=dep[y])x=p[x][k];
    if(x==y)return x;
    for(int k=M-1;k>=0;k--)if(p[x][k]!=p[y][k]){x=p[x][k];y=p[y][k];}
    return p[x][0];
}
ll Query(int x,int y,int t){
    ll ans=-inf;
    if(dep[x]<dep[y])swap(x,y);
    for(int k=M-1;k>=0;k--)
        if(dep[x]-(1<<k)>=dep[y]){
            ans=max(ans,Max[t][x][k]);
            x=p[x][k];
        }
    if(x==y)return ans;
    for(int k=M-1;k>=0;k--)
        if(p[x][k]!=p[y][k]){
            ans=max(ans,Max[t][x][k]);
            ans=max(ans,Max[t][y][k]);
            x=p[x][k];y=p[y][k];
        }
    return max(ans,max(Max[t][x][0],Max[t][y][0]));
}
int main(){
    for(int i=0;i<M;i++)Max[0][0][i]=Max[1][0][i]=Max[0][1][i]=Max[1][1][i]=-inf;
    int T=read();
    while(T--){
        n=read();m=read();
        for(int i=1;i<=m;i++){
            P[i].x=read();P[i].y=read();P[i].w=read();
        }
        sort(P+1,P+m+1,cmp);
        for(int i=1;i<=n;i++)fa[i]=i;
        ll sum=0;
        int num=0;
        for(int i=1;i<=m;i++){
            int x=Find(P[i].x),y=Find(P[i].y);
            if(x==y)continue;
            sum+=P[i].w;
            fa[x]=y;
            G[P[i].x].push_back(mp(P[i].y,P[i].w));
            G[P[i].y].push_back(mp(P[i].x,P[i].w));
            num++;
        }
        if(num!=n-1){puts("-1 -1");Clear();continue;}
        DFS(1,1);
        ll ans1=sum,ans2=inf;
        for(int i=1;i<=m;i++){
            int x=P[i].x,y=P[i].y,w=P[i].w;
            int z=LCA(x,y);
            ll val=Query(x,y,!(w&1));
            if(val==-inf)continue;
            // cout<<"Query:"<<!(w&1)<<": "<<x<<" "<<y<<" "<<val<<endl;
            ans2=min(ans2,ans1-val+w);
        }
        if(ans2==inf)ans2=-1;
        if(ans1&1)swap(ans1,ans2);
        printf("%lld %lld\n",ans1,ans2);
        Clear();
    }
    return 0;
}