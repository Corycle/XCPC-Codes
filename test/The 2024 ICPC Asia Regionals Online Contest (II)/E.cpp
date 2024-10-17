#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,D;
int vis[N],dis[N],pre[N],vst[N],dist[N];
vector<int>G[N];
void Clear(){
    for(int i=1;i<=n*2;i++)G[i].clear();
}
void BFS1(){
    for(int i=1;i<=n*2;i++)vis[i]=dis[i]=0;
    int K=read();
    queue<int>q;
    for(int i=1;i<=K;i++){
        int x=read();
        q.push(x);
        vis[x]=1;
    }
    while(!q.empty()){
        int x=q.front();q.pop();
        for(auto y:G[x]){
            if(vis[y])continue;
            vis[y]=1;
            dis[y]=dis[x]+1;
            if(dis[y]!=D)q.push(y);
        }
    }
}
void BFS2(){
    for(int i=1;i<=n*2;i++)vst[i]=dist[i]=pre[i]=0;
    queue<int>q;q.push(1);vst[1]=1;
    while(!q.empty()){
        int x=q.front();q.pop();
        for(auto y:G[x]){
            if(vst[y])continue;
            if(vis[y]&&dist[x]+1>=dis[y])continue;
            vst[y]=1;
            dist[y]=dist[x]+1;
            q.push(y);
            pre[y]=x;
        }
    }
}
void Print(int x){
    if(pre[x])Print(pre[x]);
    printf("%d ",x>n?x-n:x);
}
int main(){
    int T=read();
    while(T--){
        n=read();m=read();D=read();
        for(int i=1;i<=m;i++){
            int x=read(),y=read();
            G[x].push_back(y+n);
            G[y].push_back(x+n);
            G[x+n].push_back(y);
            G[y+n].push_back(x);
        }
        BFS1();
        BFS2();
        if(vst[n]&&vst[n*2]){
            if(dist[n]<dist[n*2]){
                printf("%d\n",dist[n]);
                Print(n);
                puts("");
            }
            else{
                printf("%d\n",dist[n*2]);
                Print(n*2);
                puts("");
            }
        }
        else if(vst[n]){
            printf("%d\n",dist[n]);
            Print(n);
            puts("");
        }
        else if(vst[n*2]){
            printf("%d\n",dist[n*2]);
            Print(n*2);
            puts("");
        }
        else puts("-1");
        Clear();
    }
    return 0;
}