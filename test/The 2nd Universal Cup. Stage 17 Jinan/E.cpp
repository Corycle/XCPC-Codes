#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e6+5;
ll read(){
    ll s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
vector<int>G[N];
int n,m,S,T,cnt,tot;
int h[N],H[N],dis[N],vis[N],col[N],vst[N];
void Clear(){
    for(int i=1;i<=tot;i++){
        h[i]=0;
        vis[i]=0;
        col[i]=0;
        G[i].clear();
    }
    for(int i=1;i<=m;i++)vst[i]=0;
    cnt=1;
}
struct Edge{int x,y;}E[N]; 
struct edge{int to,next,flow;}d[N];
void Add(int x,int y,int z){
    d[++cnt]=(edge){y,h[x],z};h[x]=cnt;
    d[++cnt]=(edge){x,h[y],0};h[y]=cnt;
}
bool BFS(int s,int t){
    for(int i=1;i<=tot;i++){dis[i]=-1;H[i]=h[i];}
    queue<int>q;q.push(s);dis[s]=0;
    while(q.size()){
        int x=q.front();q.pop();
        if(x==t)return true;
        for(int i=h[x];i;i=d[i].next){
            int y=d[i].to;
            if(d[i].flow&&dis[y]==-1){
                dis[y]=dis[x]+1;
                q.push(y);
            }
        }
    }
    // cout<<1<<endl;
    return false;
}
int DFS(int x,int maxn,int t){
    if(x==t||!maxn)return maxn;
    int ans=0;
    for(int &i=H[x];i;i=d[i].next){
        int y=d[i].to;
        if(d[i].flow&&dis[y]==dis[x]+1){
            int dlt=DFS(y,min(maxn,d[i].flow),t);
            if(!dlt)dis[y]=-1;
            d[i].flow-=dlt;
            d[i^1].flow+=dlt;
            maxn-=dlt;ans+=dlt;
            if(!maxn)return ans;
        }
    }
    return ans;
}
int Dinic(int s,int t){
    int ans=0;
    while(BFS(s,t)){
        // cout<<"1111"<<endl;
        ans+=DFS(s,inf,t);
    }
    return ans;
}
void Calc(int x,int c){
    col[x]=c;
    for(auto y:G[x]){
        if(col[y])continue;
        Calc(y,c);
    }
}
int main(){
    int Case=read();
    while(Case--){
        cnt=1;
        n=read();m=read();S=n*2+1;T=n*2+2;tot=n*2+2;
        for(int i=1;i<=m;i++){
            int x=read(),y=read();
            Add(x,y+n,1);
            E[i].x=x;E[i].y=y;
        }
        for(int i=1;i<=n;i++){
            Add(S,i,1);
            Add(i+n,T,1);
        }
        Dinic(S,T);
        for(int x=1;x<=n;x++){
            for(int i=h[x];i;i=d[i].next){
                int y=d[i].to;
                if(y>n&&y<=2*n&&d[i].flow==0){
                    vst[i>>1]=1;
                    vis[x]=vis[y]=1;
                }
            }
        }
        // for(int i=1;i<=m;i++)cout<<vst[i]<<" ";cout<<endl;
        // for(int i=1;i<=n*2;i++)cout<<vis[i]<<" ";cout<<endl;
        int num1=0,num2=0,num3=0,num4=0;

        for(int i=1;i<=tot;i++){col[i]=0;G[i].clear();}
        for(int i=1;i<=m;i++){
            if(vst[i])G[E[i].y+n].push_back(E[i].x);
            else G[E[i].x].push_back(E[i].y+n);
        }
        for(int i=1;i<=n;i++)if(!vis[i])G[S].push_back(i);
        Calc(S,1);
        for(int i=1;i<=n;i++)if(col[i]==1)num1++;
        for(int i=n+1;i<=n*2;i++)if(col[i]==1)num2++;

        for(int i=1;i<=tot;i++){col[i]=0;G[i].clear();}
        for(int i=1;i<=m;i++){
            if(vst[i])G[E[i].x].push_back(E[i].y+n);
            else G[E[i].y+n].push_back(E[i].x);
        }
        for(int i=n+1;i<=n*2;i++)if(!vis[i])G[T].push_back(i);
        Calc(T,2);
        for(int i=1;i<=n;i++)if(col[i]==2)num3++;
        for(int i=n+1;i<=n*2;i++)if(col[i]==2)num4++;
        
        // cout<<num1<<" "<<num2<<" "<<num3<<" "<<num4<<endl;
        printf("%lld\n",1ll*num1*num4);

        Clear();
    }
    return 0;
}