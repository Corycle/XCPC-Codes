/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int Mod=998244353;
const int N=55;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,K,Ans,a[N][N],fac[N];
struct UnionSet{
    int fa[N],sum[N];
    void Init(){for(int i=1;i<=n;i++){fa[i]=i;sum[i]=1;}}
    int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
    void Union(int x,int y){x=Find(x);y=Find(y);if(x!=y){fa[x]=y;sum[y]+=sum[x];}}
}F1,F2;
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();K=read();Ans=fac[0]=1;
    for(int i=1;i<=n;i++){
        fac[i]=1ll*fac[i-1]*i%Mod;
        for(int j=1;j<=n;j++)a[i][j]=read();
    }
    F1.Init();F2.Init();
    for(int x=1;x<=n;x++){
        for(int y=1;y<=n;y++){
            int flag1=1,flag2=1;
            for(int i=1;i<=n;i++){
                flag1&=(a[i][x]+a[i][y]<=K);
                flag2&=(a[x][i]+a[y][i]<=K);
            }
            if(flag1)F1.Union(x,y);
            if(flag2)F2.Union(x,y);
        }
    }
    for(int i=1;i<=n;i++){
        if(i==F1.fa[i])Ans=1ll*Ans*fac[F1.sum[i]]%Mod;
        if(i==F2.fa[i])Ans=1ll*Ans*fac[F2.sum[i]]%Mod;
    }
    printf("%d\n",Ans);
	return 0;
}
