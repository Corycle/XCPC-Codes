#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Mod=998244353;
const int N=2e6+5;
const int M=21;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,cnt,Ans=1;
int h[N],fa[N],Fa[N],num[N],inv[N],tot[N],dep[N],son[N],top[N],sum[N];
struct edge{int to,next;}d[N];
void Add(int x,int y){d[++cnt]=(edge){y,h[x]};h[x]=cnt;}
int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
void DFS1(int x,int depth){
	dep[x]=depth;sum[x]=1;
	for(int i=h[x];i;i=d[i].next){
		int y=d[i].to;
		DFS1(y,depth+1);
		sum[x]+=sum[y];
		if(sum[son[x]]<sum[y])son[x]=y;
	}
}
void DFS2(int x,int tp){
	top[x]=tp;
	if(son[x])DFS2(son[x],tp);
	for(int i=h[x];i;i=d[i].next){
		int y=d[i].to;
		if(y==son[x])continue;
		DFS2(y,y);
	}
}
int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=Fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
int main(){
	n=read();m=n;
	inv[0]=inv[1]=1;
	for(int i=2;i<N;i++)inv[i]=1ll*inv[Mod%i]*(Mod-Mod/i)%Mod;
	for(int i=1;i<=n;i++){fa[i]=i;num[i]=1;}
	for(int i=1;i<n;i++){
		int x=read(),y=read(),z=++m;
		x=Find(x);y=Find(y);
		Ans=1ll*Ans*inv[num[x]]%Mod*inv[num[y]]%Mod;
		fa[x]=fa[y]=fa[z]=z;num[z]=num[x]+num[y];
		Fa[x]=Fa[y]=z;
		Add(z,x);Add(z,y);
	}
	DFS1(m,1);DFS2(m,m);
//	for(int i=1;i<=m;i++)cout<<top[i]<<" ";cout<<endl;
	for(int i=1;i<n;i++){
		int x=read(),y=read();
//		cout<<LCA(x,y)<<" "<<endl;
		tot[LCA(x,y)]++;
	}
	for(int i=n+1;i<=m;i++){
		if(tot[i]!=1)Ans=0;
	}
	printf("%d\n",Ans);
    return 0;
}
