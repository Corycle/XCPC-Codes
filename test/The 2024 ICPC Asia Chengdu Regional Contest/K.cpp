#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define int long long
using namespace std;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
/*----------*/
const int N = 3000006, INF = 1e9;
int n,cnt=1;
int h[N],dis[N],vis[N],pre[N];
struct edge{
    int to,next,flow,cost;
}d[N*10];
void Add(int x,int y,int f,int c){
    d[++cnt]=(edge){y,h[x],f,c};h[x]=cnt;
    d[++cnt]=(edge){x,h[y],0,-c}; h[y]=cnt;
}
bool SPFA(int s,int t){
    for(int i=1;i<=n;++i) {dis[i]=INF;vis[i]=0;}
    queue<int>q;
    q.push(s);
    dis[s]=0;
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
    return dis[t]!=INF;
}
int DFS(int x,int maxn,int t){
    if(x==t||!maxn) return maxn;
    int ans=0;vis[x]=1;
    for(int i=h[x];i;i=d[i].next){
        int y=d[i].to;
        if(d[i].flow&&!vis[y]&&dis[y]==dis[x]+d[i].cost){
            int dlt=DFS(y,min(maxn,d[i].flow),t);
            if(!dlt)dis[y]=-1;
            d[i].flow-=dlt;
            d[i^1].flow+=dlt;
            ans+=dlt;maxn-=dlt;
            if(!maxn) return ans;
        }
    }
    return ans;
}
int Flow,Cost;
void ZKW(int s,int t){
    while(SPFA(s,t)){
        int flow=DFS(s,INF,t);
        Flow+=flow;
        Cost+=flow*dis[t];
    }
}
/*----------*/
/*========*/
int P[100000];
int gcd(int a,int b){
    return __gcd(a,b);
}
int Rand(int maxn){
    return (1ll*rand()*rand()+rand())%maxn+1;
}
inline int Multi(int x,int y,int mod){return 1ll*x*y%mod;}
int Pow(int x,int y,int mod){
    int ans=1,base=x;
    for(int i=1;i<=y;i<<=1){
        if(y&i) ans=1ll*ans*base%mod;
        base=1ll*base*base%mod;
    }
    return ans;
}
bool Miller_Rabin(int n){
    if(n==2) return true;
    if(n<2||!(n&1)) return false;
    int m = n - 1, k = 0 ;
    while(!(m&1)){k++;m>>=1;}
    for(int i=1;i<=10;++i){
        int a=Rand(n-1),x=Pow(a,m,n),y=0;
        for(int j=1;j<=k;++j){
            y=x;
            x=Multi(x,x,n);
            if(x==1&&y!=1&&y!=n-1) return false;
        }
        if(x!=1) return false;
    }
    return true;
}
int Pollard_rho(int n,int c){
    int x=Rand(n-1),y=x,z=1,i=1,k=2;
    while(1){
        i++;
        x=(Multi(x,x,n)+c)%n;
        z=Multi(z,abs(y-x),n);
        if(x==y||!z) return n;
        if(i%127==0||i==k){
            int d = gcd(z,n);
            if(d>1) return d;
            if(i==k) {y=x;k<<=1;}
        }
    }
}
void Solve(int n,int c){
    if(n==1) return ;
    if(Miller_Rabin(n)) {P[++P[0]]=n;return;}
    long long p = n;
    while(p==n) p=Pollard_rho(n,c--);
    Solve(p,c);Solve(n/p,c);
}
/*=========*/
int NN,a[500];
map<int,int> id;
int dd(int x){
    P[0]=0;
    Solve(x,10000007);
    return P[0];
}
signed main(){
    srand(time(0));
    NN=read();
    for(int i=1;i<=NN;++i) a[i]=read();
    int S = NN+1, T = NN+2;
    n=NN+2;
    for(int i=1;i<=NN;++i){
        Add(S,i,1,0);
        for(int j=1;j*j<=a[i];++j) if(a[i]%j==0) {
            if(id[j]==0){
                id[j]=++n;
                Add(n,T,1,dd(j));
            }
            Add(i,id[j],1,0);
            if(id[a[i]/j]==0){
                id[a[i]/j]=++n;
                Add(n,T,1,dd(a[i]/j));
            }
            if(j*j!=a[i]) Add(i,id[a[i]/j],1,0);
        }
    }
    ZKW(S,T);
    int ans = 0;
    for(int i=1;i<=NN;++i) ans += dd(a[i]);
    ans -= Cost;
    // cout<<"DEUBG: "<<Flow<<" "<<Cost<<endl;
    cout<<ans;
    // for(auto x:id){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
}