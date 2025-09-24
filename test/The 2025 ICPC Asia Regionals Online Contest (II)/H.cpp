#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,popcnt,fma")
using namespace std;
const int inf=0x3f3f3f3f;
const int Mod=998244353;
const int N=1e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,vis[N],dis[N],fac[N];
vector<int>G[N];
void Clear(){
	for(int i=1;i<=n;i++){
		G[i].clear();
	}
}
int Calc(int k){
	if(k==2)return 1;
	return (fac[k]-2ll*fac[k-1]%Mod+fac[k-2]+Mod)%Mod;
}
int BFS(int s){
	for(int i=1;i<=n;i++){vis[i]=0;dis[i]=0;}
	queue<int>q;q.push(s);dis[s]=1;
	int ans=0;
	while(q.size()){
		int x=q.front();q.pop();
		for(auto y:G[x]){
			if(vis[y])continue;
			vis[y]=1;
			dis[y]=dis[x]+1;
			q.push(y);
			if(y>s){
				ans=(ans+Calc(dis[y]))%Mod;
			}
		}
	}
	return ans;
}
void Prepare(){
	fac[0]=fac[1]=1;
	for(int i=2;i<N;i++)fac[i]=1ll*fac[i-1]*i%Mod;
}
int main(){
	Prepare();
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<n;i++){
			int x=read(),y=read();
			G[x].push_back(y);
			G[y].push_back(x);
		}
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans+BFS(i))%Mod;
		}
		printf("%d\n",ans);
		Clear();
	}
	return 0;
}
