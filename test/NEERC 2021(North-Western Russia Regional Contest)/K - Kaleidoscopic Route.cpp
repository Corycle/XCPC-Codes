#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,cnt;
int h[N],vis[N],Max1[N],Min1[N],Max2[N],Min2[N],dis1[N],dis2[N];
struct edge{int to,next,col;}d[N*2];
void Add(int x,int y,int z){d[++cnt]=(edge){y,h[x],z};h[x]=cnt;}
void BFS(int S,int Max[],int Min[],int dis[]){
	for(int i=1;i<=n;i++){vis[i]=0;Max[i]=-inf;Min[i]=inf;}
	queue<int>q;q.push(S);vis[S]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=h[x];i;i=d[i].next){
			int y=d[i].to;
			if(!vis[y]){vis[y]=1;dis[y]=dis[x]+1;q.push(y);}
			if(dis[y]==dis[x]+1){
				Max[y]=max(max(Max[x],Max[y]),d[i].col);
				Min[y]=min(min(Min[x],Min[y]),d[i].col);
			}
		}
	}
}
int a[N];
int main(){
	n=read();m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		Add(x,y,z);Add(y,x,z);
	}
	BFS(1,Max1,Min1,dis1);
	BFS(n,Max2,Min2,dis2);
	printf("%d\n",dis1[n]);
	if(dis1[n]==1){printf("1 %d\n",n);return 0;}
	int P=0,t=0,Max=0;
	for(int i=2;i<n;i++){
		if(dis1[i]+dis2[i]!=dis1[n])continue;
		if(Max1[i]-Min2[i]>Max){Max=Max1[i]-Min2[i];P=i;t=0;}
		if(Max2[i]-Min1[i]>Max){Max=Max2[i]-Min1[i];P=i;t=1;}
	}
	a[++a[0]]=P;
	int x=P,flag=0;
	while(x!=1){
		for(int i=h[x];i;i=d[i].next){
			int y=d[i].to;
			if(dis1[x]!=dis1[y]+1)continue;
			if(t==0&&d[i].col==Max1[P])flag=1;
			if(t==1&&d[i].col==Min1[P])flag=1;
			if(!flag){
				if(t==0&&Max1[x]!=Max1[y])continue;
				if(t==1&&Min1[x]!=Min1[y])continue;
			}
			x=y;break;
		}
		a[++a[0]]=x;
	}
	reverse(a+1,a+a[0]+1);
	x=P;flag=0;
	while(x!=n){
		for(int i=h[x];i;i=d[i].next){
			int y=d[i].to;
			if(dis2[x]!=dis2[y]+1)continue;
			if(t==0&&d[i].col==Min2[P])flag=1;
			if(t==1&&d[i].col==Max2[P])flag=1;
			if(!flag){
				if(t==0&&Min2[x]!=Min2[y])continue;
				if(t==1&&Max2[x]!=Max2[y])continue;
			}
			x=y;break;
		}
		a[++a[0]]=x;
	}
	for(int i=1;i<=a[0];i++)printf("%d ",a[i]);
	return 0;
}
