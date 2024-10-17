#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int M=22;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,a[N],p[N][M],dep[N],sum[N][M];
vector<int>G[N];
void DFS(int x,int pre,int depth){
	p[x][0]=pre;dep[x]=depth;
	for(int i=1;i<M;i++)p[x][i]=p[p[x][i-1]][i-1];
	for(int i=1;i<=20;i++)sum[x][i]=sum[pre][i]+(a[x]==i);
	for(auto y:G[x]){
		if(y==pre)continue;
		DFS(y,x,depth+1);
	}
}
int LCA(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int k=M-1;k>=0;k--)if(dep[x]-(1<<k)>=dep[y])x=p[x][k];
	if(x==y)return x;
	for(int k=M-1;k>=0;k--)if(p[x][k]!=p[y][k]){x=p[x][k];y=p[y][k];}
	return p[x][0];
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	DFS(1,0,1);
	while(m--){
		int x=read(),y=read();
		int z=LCA(x,y),ans=0;
		for(int i=1;i<=20;i++){
			ans+=((sum[x][i]+sum[y][i]-sum[z][i]-sum[p[z][0]][i])!=0);
		}
		printf("%d\n",ans);
	}
	return 0;
}
