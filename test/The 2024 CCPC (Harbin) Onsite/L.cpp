#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
const int Mod=998244353;
const int Inv2=499122177;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
vector<int>G[N];
int n,m,Ans,sum[N],f1[N],f2[N],dep[N],g[N],g0[N],g1[N],g2[N];
int mod(int x){return x>=Mod?x-Mod:x;}
int Pow(int x,int y){
    int ans=1;
    while(y){if(y&1)ans=1ll*ans*x%Mod;x=1ll*x*x%Mod;y>>=1;}
    return ans;
}
int Inv(int x){return Pow(x,Mod-2);}
void DFS(int x,int fa){
    sum[x]=1;
    f1[x]=dep[x]=dep[fa]+1;
    f2[x]=1ll*dep[x]*dep[x]%Mod;
    int num=0;
    for(auto y:G[x]){
        if(y==fa)continue;
        DFS(y,x);
        num++;
        sum[x]+=sum[y];
        f1[x]=mod(f1[x]+f1[y]);
        f2[x]=mod(f2[x]+f2[y]);
    }
    g[x]=(sum[x]-1)*2+1;
    for(auto y:G[x]){
        if(y==fa)continue;
        g[x]=(g[x]+1ll*sum[y]*(sum[x]-sum[y]-1)%Mod)%Mod;
    }
    g0[x]=g[x];
    g1[x]=1ll*g0[x]*dep[x]%Mod;
    g2[x]=1ll*g1[x]*dep[x]%Mod;
    ll t=(n*2-1+1ll*(n-sum[x])*(sum[x]-1)%Mod)%Mod;
    // cout<<"t: "<<x<<" "<<t<<endl;
    for(auto y:G[x]){
        if(y==fa)continue;
        g0[x]=mod(g0[x]+g0[y]);
        g1[x]=mod(g1[x]+g1[y]);
        g2[x]=mod(g2[x]+g2[y]);
        t=(t+1ll*sum[y]*(n-sum[y]-1)%Mod)%Mod;
        // cout<<"t: "<<x<<" "<<t<<endl;
    }
    // cout<<"t: "<<x<<" "<<t<<endl;
    ll S1=0,S2=0;
    for(auto y:G[x]){
        if(y==fa)continue;
        
        int fxy=(t-2ll*sum[y]*(n-sum[y])%Mod+Mod)%Mod;
        // cout<<"f: "<<x<<" "<<y<<" "<<fxy<<endl;
        S1=(S1+1ll*fxy*(g2[y]+1ll*dep[x]*dep[x]%Mod*g0[y]%Mod-2ll*g1[y]*dep[x]%Mod+Mod)%Mod)%Mod;
        
        S2=(S2+1ll*g2[y]*(g0[x]-g0[y]-g[x])%Mod+Mod)%Mod;
        S2=(S2+1ll*(g2[x]-g2[y]-1ll*dep[x]*dep[x]%Mod*g[x]%Mod)%Mod*g0[y]%Mod+Mod)%Mod;
        S2=(S2+4ll*dep[x]*dep[x]%Mod*g0[y]%Mod*(g0[x]-g0[y]-g[x])%Mod+Mod)%Mod;
        S2=(S2+2ll*g1[y]*(g1[x]-g1[y]-1ll*dep[x]*g[x]%Mod)%Mod+Mod)%Mod;
        S2=(S2-4ll*dep[x]*g1[y]%Mod*(g0[x]-g0[y]-g[x])%Mod+Mod)%Mod;
        S2=(S2-4ll*dep[x]*(g1[x]-g1[y]-1ll*dep[x]*g[x])%Mod*g0[y]%Mod+Mod)%Mod;

    }
    S2=1ll*S2*Inv2%Mod;
    // cout<<"Sovle: "<<x<<" "<<g[x]<<" "<<S1<<" "<<S2<<endl;
    Ans=mod(Ans+mod(S1+S2));
}
void Work(){
    n=read();
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        G[x].push_back(y);
        G[y].push_back(x);
    }
    DFS(1,0);
    // printf("%d\n",Ans);
    int num=(1ll*n*(n-1)/2)%Mod;
    Ans=1ll*Ans*Inv(1ll*num*num%Mod)%Mod;
    printf("%d\n",Ans);
}
void Clear(){
    Ans=0;
    for(int i=1;i<=n;i++){
        G[i].clear();
        f1[i]=f2[i]=g[i]=g0[i]=g1[i]=g2[i]=sum[i]=dep[i]=0;
    }
}
int main(){
    int T=read();
    while(T--){
        Work();
        Clear();
    }
    return 0;
}