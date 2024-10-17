#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int Mod=998244353;
const int N=5005;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int inv(int x){
    int res=1,base=x,b=Mod-2;
    for(int i=1;i<=b;i<<=1){
        if(i&b) res=1ll*res*base%Mod;
        base=1ll*base*base%Mod;
    }
    return res;
}
int n,a[5050],F[5050],father[5050];
int find(int x){return F[x]==x?x:F[x]=find(F[x]);}
void merge(int x,int y){F[find(x)]=find(y);}
bool vis[5050];
vector<int>e[N];
int l[5050],f[5050],g[5050],base[5050];
// pair<int,int> dp(int cur){
//     for(auto x:e[cur]) if(vis[x]&&x!=father[cur]) dp(x);
//     for(auto x:e[cur]) if(!vis[x]&&x!=father[cur]) ++l[cur];
//     f[cur]=base[l[cur]];
//     for(auto x:e[cur]) if(vis[x]&&x!=father[cur]) f[cur]=f[cur]*(f[x]+2ll*g[x])%Mod;
//     int tmp=1;
//     for(auto x:e[cur]) if(vis[x]&&x!=father[cur]) tmp=tmp*(f[x]+2ll*g[x])%Mod;
//     if(l[cur]) g[cur]=l[cur]*499122177ll%Mod;
//     else g[cur]=0;
//     for(auto x:e[cur]) if(vis[x]&&x!=father[cur]) g[cur]=g[cur]*(f[x]+2ll*g[x])%Mod;
//     for(auto x:e[cur]) if(vis[x]&&x!=father[cur]) g[cur]=(g[cur]+1ll*g[x]*tmp%Mod*inv((f[x]+2ll*g[x])%Mod))%Mod;
//     g[cur]=1ll*g[cur]*base[l[cur]]%Mod;
//     return make_pair(f[cur],g[cur]);
// }
void upd(int cur){
    f[cur]=base[l[cur]];
    for(auto x:e[cur]) if(vis[x]&&x!=father[cur]) f[cur]=f[cur]*(f[x]+2ll*g[x])%Mod;
    int tmp=1;
    for(auto x:e[cur]) if(vis[x]&&x!=father[cur]) tmp=tmp*(f[x]+2ll*g[x])%Mod;
    if(l[cur]) g[cur]=l[cur]*499122177ll%Mod;
    else g[cur]=0;
    for(auto x:e[cur]) if(vis[x]&&x!=father[cur]) g[cur]=g[cur]*(f[x]+2ll*g[x])%Mod;
    for(auto x:e[cur]) if(vis[x]&&x!=father[cur]) g[cur]=(g[cur]+1ll*g[x]*tmp%Mod*inv((f[x]+2ll*g[x])%Mod))%Mod;
    g[cur]=1ll*g[cur]*base[l[cur]]%Mod;
}
int work(int workcnt){
    for(int i=1;i<=n;++i) l[i]=0;
    for(int i=1;i<=n;++i)
        for(auto x:e[i]) if(!vis[x]&&x!=father[i])
            ++l[i];
    for(int i=a[workcnt];i;i=father[i]){
        upd(i);
    }
    int ans=1;
    for(int i=1;i<=n;++i) if(vis[i]&&!vis[father[i]]){
        // auto x=dp(i);
        // printf("f[%lld]=%lld g[%lld]=%lld\n",i,x.first,i,x.second);
        if(father[i]) ans=ans*(f[i]+2ll*g[i])%Mod;
        else ans=1ll*ans*g[i]%Mod;
    }
    // for(int i=1;i<=n;++i) printf("f[%lld]=%lld g[%lld]=%lld\n",i,f[i],i,g[i]);
    return ans;
}
void dfs(int cur,int fa){
    father[cur]=fa;
    for(auto x:e[cur]){
        if(x!=fa) dfs(x,cur);
    }
}
int main(){
    n=read();base[0]=1;
    for(int i=1;i<=n;++i) F[i]=i,base[i]=base[i-1]*2ll%Mod;
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1,0);
    for(int i=1;i<n;++i) a[i]=read();
    for(int i=1;i<n;++i){
        vis[a[i]]=true;
        for(auto x:e[a[i]]){
            if(vis[x]) merge(a[i],x);
        }
        printf("%d\n",work(i));
    }
    return 0;
}