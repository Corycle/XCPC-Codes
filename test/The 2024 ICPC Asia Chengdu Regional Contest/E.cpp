#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
const int N=1e5+5;
const int M=20;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
vector<int>G[N],Q[N];
int n,m,f[N],g[N],fa[N],p[N][M],dep[N],ans[N],sum[N];
int Pow(int x,int y){int ans=1;while(y){if(y&1)ans=1ll*ans*x%Mod;x=1ll*x*x%Mod;y>>=1;}return ans;}
int Inv(int x){return Pow(x,Mod-2);}
void DFS1(int x){
    p[x][0]=fa[x];
    for(int i=1;i<M;i++)p[x][i]=p[p[x][i-1]][i-1];
    f[x]=1;g[x]=0;
    for(auto y:G[x]){
        if(y==fa[x])continue;
        DFS1(y);
        f[x]=1ll*f[x]*(f[y]+1)%Mod;
        g[x]=(g[x]+g[y])%Mod;
    }
    g[x]=(g[x]+f[x])%Mod;
}
void DFS2(int x){
    dep[x]=dep[fa[x]]+1;
    sum[x]=(sum[fa[x]]+f[x])%Mod;
    for(auto y:G[x]){
        if(y==fa[x])continue;
        DFS2(y);
    }
}
void DFS3(int x){
    int tf1=f[x],tg1=g[x];
    if(fa[x]){
        f[x]=1;g[x]=0;
        for(auto y:G[x]){
            f[x]=1ll*f[x]*(f[y]+1)%Mod;
            g[x]=(g[x]+g[y])%Mod;
        }
        g[x]=(g[x]+f[x])%Mod;
        for(auto id:Q[x]){
            ans[id]=(ans[id]+g[fa[x]])%Mod;
        }
    }
    int num=G[x].size();
    if(num){
        vector<int>sum1,sum2;
        sum1.resize(num);
        sum2.resize(num);
        sum1[0]=f[G[x][0]]+1;
        sum2[num-1]=f[G[x][num-1]]+1;
        for(int i=1;i<num;i++)sum1[i]=1ll*sum1[i-1]*(f[G[x][i]]+1)%Mod;
        for(int i=num-2;i>=0;i--)sum2[i]=1ll*sum2[i+1]*(f[G[x][i]]+1)%Mod;
        int tf2=f[x],tg2=g[x];
        for(int i=0;i<num;i++){
            int y=G[x][i];
            if(y==fa[x])continue;
            g[x]=(g[x]-f[x]+Mod)%Mod;
            g[x]=(g[x]-g[y]+Mod)%Mod;
            f[x]=1;
            if(i)f[x]=1ll*f[x]*sum1[i-1]%Mod;
            if(i!=num-1)f[x]=1ll*f[x]*sum2[i+1]%Mod;
            // f[x]=1ll*f[x]*Inv(f[y]+1)%Mod;
            g[x]=(g[x]+f[x])%Mod;
            DFS3(y);
            f[x]=tf2;g[x]=tg2;
        }
    }
    f[x]=tf1;g[x]=tg1;
}
int LCA(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    for(int k=M-1;k>=0;k--)if(dep[x]-(1<<k)>=dep[y])x=p[x][k];
    if(x==y)return x;
    for(int k=M-1;k>=0;k--)if(p[x][k]!=p[y][k]){x=p[x][k];y=p[y][k];}
    return p[x][0];
}
void Clear(){
    for(int i=1;i<=n;i++){
        fa[i]=f[i]=g[i]=dep[i]=sum[i]=0;
        G[i].clear();
        Q[i].clear();
        for(int j=0;j<M;j++)p[i][j]=0;
    }
    for(int i=1;i<=m;i++){
        ans[i]=0;
    }
}
int main(){
    int T=read();
    while(T--){
        n=read();m=read();
        for(int i=2;i<=n;i++){
            fa[i]=read();
            G[fa[i]].push_back(i);
            G[i].push_back(fa[i]);
        }
        DFS1(1);
        DFS2(1);
        for(int i=1;i<=m;i++){
            int x=read(),y=read();
            int z=LCA(x,y);
            ans[i]=(g[z]-((1ll*sum[x]+sum[y]-sum[z]-sum[fa[z]])%Mod+Mod)%Mod+Mod)%Mod;
            Q[z].push_back(i);
        }
        DFS3(1);
        for(int i=1;i<=m;i++){
            printf("%d\n",(g[1]-ans[i]+Mod)%Mod);
        }
        Clear();
    }
    return 0;
}
/*
1
5 3
1 1 2 2
4 5
2 4
2 3
*/