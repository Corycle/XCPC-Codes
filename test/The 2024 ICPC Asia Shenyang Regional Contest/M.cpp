#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
ll dis[N];
vector<int>G[N];
int n,m,Q,cnt,h[N],vis[N],ans[N];
struct edge{int to,next,dist;}d[N];
void Add(int x,int y,int z){
    // cout<<"Add: "<<x<<" "<<y<<" "<<z<<endl;
    d[++cnt]=(edge){y,h[x],z};h[x]=cnt;
    G[y].push_back(x);
}
bool SPFA(int x){
    vis[x]=1;
    for(int i=h[x];i;i=d[i].next){
        int y=d[i].to;
        if(dis[y]>dis[x]+d[i].dist){
            dis[y]=dis[x]+d[i].dist;
            if(ans[y]){vis[x]=0;return true;}
            if(vis[y]){ans[x]=1;vis[x]=0;return true;}
            if(SPFA(y)){ans[x]=1;vis[x]=0;return true;}
        }
    }
    vis[x]=0;
    return false;
}
void Solve(){
    for(int i=0;i<n;i++)dis[i]=0;
    for(int i=0;i<n;i++){
        if(ans[i])continue;
        dis[i]=0;
        SPFA(i);
    }
}
void BFS(){
    queue<int>q;
    for(int i=0;i<n;i++)if(ans[i])q.push(i);
    while(q.size()){
        int x=q.front();q.pop();
        for(auto y:G[x]){
            if(!ans[y]){
                ans[y]=1;
                q.push(y);
            }
        }
    }
}
int main(){
    n=read();m=read();Q=read();
    for(int i=1;i<=m;i++){
        int a=read(),b=read();
        if(!b)continue;
        Add((a%n+n)%n,((a+b)%n+n)%n,b);
    }
    Solve();
    for(int i=1;i<=cnt;i++)d[i].dist*=-1;
    Solve();
    BFS();
    while(Q--){
        int a=(read()%n+n)%n;
        puts(ans[a]?"Yes":"No");
    }
    return 0;
}