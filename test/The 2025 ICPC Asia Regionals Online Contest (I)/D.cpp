#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,a[N],deg[N];
ll f[N][3];
vector<int>G[N];
void DFS(int x,int fa){
	ll sum=0;
	for(auto y:G[x]){
		if(y==fa)continue;
		DFS(y,x);
		sum+=max(max(f[y][0],f[y][1]),f[y][2]);
	}
	f[x][0]=f[x][1]=f[x][2]=sum;
	ll max1=0,max2=0;
	for(auto y:G[x]){
		if(y==fa)continue;
		ll valY=max(max(f[y][0],f[y][1]),f[y][2]);
		ll val=sum-valY;
		if(a[y]>=a[x])f[x][0]=max(f[x][0],val+f[y][0]+a[y]-a[x]);
		if(a[y]<=a[x])f[x][1]=max(f[x][1],val+f[y][1]+a[x]-a[y]);
		if(a[y]>a[x]){
			max1=max(max1,f[y][0]+a[y]-a[x]-valY);
		}
		if(a[y]<a[x]){
			max2=max(max2,f[y][1]+a[x]-a[y]-valY);
		}
	}
	f[x][2]=max(f[x][2],sum+max1+max2);
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
		deg[x]++;deg[y]++;
	}
	DFS(1,0);
	printf("%lld\n",max(max(f[1][0],f[1][1]),f[1][2]));
	return 0;
}
