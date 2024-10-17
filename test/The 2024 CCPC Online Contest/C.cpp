#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int Mod=998244353;
const int inf=0x3f3f3f3f;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,a[N],tag[N],f[N][3],sum[N];
vector<int>G[N];
void DFS(int x,int prt){
	int num=0;
	sum[x]=tag[x];
	for(auto y:G[x]){
		if(y==prt)continue;
		DFS(y,x);
		sum[x]+=sum[y];
		num++;
	}
	if(!num){
		f[x][0]=tag[x]?0:inf;
		f[x][1]=f[x][2]=0;
		return;
	}
	int g1[5]={0},g2[5]={0};
	for(auto y:G[x]){
		if(y==prt)continue;
		for(int i=0;i<=4;i++){g1[i]=g2[i];g2[i]=inf;}
		for(int i=0;i<=4;i++){
			for(int j=0;j<=i&&j<=2;j++){
				g2[i]=min(g2[i],g1[i-j]+f[y][j]);
			}
		}
		for(int i=2;i>=0;i--){
			g2[i]=min(g2[i],g2[i+2]+1);
		}
	}
	f[x][0]=(sum[x]==0?inf:min(g2[0]+(tag[x]^1),g2[1]+1));
	f[x][1]=min(g2[0],g2[1]+1);
	f[x][2]=min(g2[0],min(g2[1],g2[2]+1));
	
	f[x][1]=min(f[x][1],f[x][0]);
	f[x][2]=min(f[x][2],f[x][1]);
//	cout<<f[x][0]<<" "<<f[x][1]<<" "<<f[x][2]<<endl;
}
void Clear(){
	for(int i=1;i<=n;i++){
		G[i].clear();
		a[i]=tag[i]=0;
	}
}
int main(){
	int T=read();
	while(T--){
		n=read();m=read();
		for(int i=1;i<=m;i++)tag[a[i]=read()]=1;
		for(int i=1;i<n;i++){
			int x=read(),y=read();
			G[x].push_back(y);
			G[y].push_back(x);
		}
		DFS(a[1],0);
		printf("%d\n",f[a[1]][1]);
		Clear();
	}
	return 0;
}
