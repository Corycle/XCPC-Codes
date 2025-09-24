#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,popcnt,fma")
using namespace std;
const int inf=0x3f3f3f3f;
const int Mod=998244353;
const int N=3000+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,Ans,f[N][N],sum[N],a[N];
vector<int> G[N];
void update(int x,int y,int c){
	if(c==1){
		sum[x]+=sum[y];
		for(int i=sum[x];i>=1;i--){
			for(int j=1;j<=sum[y]&&j<i;j++){
				f[x][i]=(f[x][i]+1ll*f[x][i-j]*f[y][j])%Mod;
			}
		}
	}
	if(c==-1){
		for(int i=1;i<=sum[x];i++){
			for(int j=1;j<=sum[y]&&j<i;j++){
				f[x][i]=(f[x][i]-1ll*f[x][i-j]*f[y][j]%Mod+Mod)%Mod;
			}
		}
		sum[x]-=sum[y];
	}
}
void Calc(int x){
//	cout<<"Calc: "<<x<<endl;
//	for(int i=1;i<=n;i++)cout<<f[x][i]<<" ";cout<<endl;
	int ans=0,Sum=0;
	for(int i=1;i<=n;i++)Sum=(Sum+f[x][i])%Mod;
	for(auto y:G[x]){
		for(int i=1;i<=n;i++)a[i]=f[x][i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=sum[y]&&j<i;j++){
				a[i]=(a[i]-1ll*a[i-j]*f[y][j]%Mod+Mod)%Mod;
			}
		}
		for(int i=n;i>=1;i--){
			for(int j=(i+1)/2;j<=sum[y]&&j<i;j++){
				ans=(ans+1ll*a[i-j]*f[y][j])%Mod;
			}
		}
	}
//	cout<<"Sum: "<<Sum<<" ans="<<ans<<endl;
	Ans=(1ll*Ans+Sum-ans+Mod)%Mod;
}
void DFS1(int x,int fa){
	sum[x]=1;
	f[x][1]=1;
	for(auto y:G[x]){
		if(y==fa)continue;
		DFS1(y,x);
		update(x,y,1);
	}
}
void DFS2(int x,int fa){
//	cout<<"DFS2: "<<x<<" "<<fa<<endl;
	if(fa){
		update(fa,x,-1);
		update(x,fa,1);
	}
	Calc(x);
	for(auto y:G[x]){
		if(y==fa)continue;
		DFS2(y,x);
	}
	if(fa){
		update(x,fa,-1);
		update(fa,x,1);
	}
}
void Clear(){
	Ans=0;
	for(int i=0;i<=n;i++){
		G[i].clear();
		for(int j=0;j<=n;j++){
			f[i][j]=0;
		}
	}
}
void DFS(int x,int fa){
	int num=1;
	for(auto y:G[x]){
		if(y==fa)continue;
		DFS(y,x);
		num+=sum[y];
	}
	for(int i=0;i<=num;i++)f[x][i]=0;
	f[x][1]=1;
	sum[x]=1;
	for(auto y:G[x]){
		if(y==fa)continue;
		update(x,y,1);
	}
}
int main(){
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<n;i++){
			int x=read(),y=read();
			G[x].push_back(y);
			G[y].push_back(x);
		}
		DFS1(1,0);
		DFS2(1,0);
		printf("%d\n",Ans);
		Clear();
	}
	return 0;
}
