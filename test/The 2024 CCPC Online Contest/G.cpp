#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int inf=2.1e9;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int Flow,Cost;
int n,m,tot,cnt=1;
int h[N],dis[N],vis[N],pre[N],a[N],V[N];
struct edge{int to,next,flow,cost;}d[N];
struct Node{int x,y,w;}P[N];
void Add(int x,int y,int f,int c){
	d[++cnt]=(edge){y,h[x],f,c};h[x]=cnt;
	d[++cnt]=(edge){x,h[y],0,-c};h[y]=cnt;
}
void Clear(){
	for(int i=1;i<=tot;i++)h[i]=0;
	cnt=1;tot=0;
	Flow=Cost=0;
}
bool SPFA(int s,int t){
	for(int i=1;i<=tot;i++){dis[i]=inf;vis[i]=0;}
	queue<int>q;q.push(s);dis[s]=0;
	while(q.size()){
		int x=q.front();q.pop();vis[x]=0;
		for(int i=h[x];i;i=d[i].next){
			int y=d[i].to;
			if(d[i].flow&&dis[y]>dis[x]+d[i].cost){
				dis[y]=dis[x]+d[i].cost;
				if(!vis[y]){vis[y]=1;q.push(y);}
			}
		}
	}
	return dis[t]!=inf;
}
int DFS(int x,int maxn,int t){
	if(x==t||!maxn)return maxn;
	int ans=0;vis[x]=1;
	for(int i=h[x];i;i=d[i].next){
		int y=d[i].to;
		if(d[i].flow&&!vis[y]&&dis[y]==dis[x]+d[i].cost){
			int dlt=DFS(y,min(maxn,d[i].flow),t);
			if(!dlt)dis[y]=-1;
			d[i].flow-=dlt;
			d[i^1].flow+=dlt;
			ans+=dlt;maxn-=dlt;
			if(!maxn)return ans;
		}
	}
	return ans;
}
void ZKW(int s,int t){
	while(SPFA(s,t)){
		int flow=DFS(s,inf,t);
		Flow+=flow;
		Cost+=flow*dis[t];
	}
}
int S,T,Sum;
void Build(int x){
	tot=n;S=++tot;T=++tot;
	for(int i=1;i<=n;i++){
		Add(S,i,min(x-(i!=1),a[i]),(i!=1));
		Add(i,T,V[i],0);
	}
	for(int i=1;i<=m;i++){
		int t=++tot;
		Add(P[i].x,t,inf,0);
		Add(P[i].y,t,inf,0);
		Add(t,T,P[i].w,0);
	}
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++){a[i]=read();V[i]=read();Sum+=V[i];}
	for(int i=1;i<=m;i++){P[i].x=read();P[i].y=read();P[i].w=read();Sum+=P[i].w;}
	Build(a[1]);
	ZKW(S,T);
//	cout<<"Sum: "<<Sum<<endl;
//	cout<<"Flow: "<<Flow<<endl;
//	cout<<"Cost: "<<Cost<<endl;
	if(Flow!=Sum){puts("NO");return 0;}
	int Maxn=Sum-Cost;
	Clear();
	Build(Maxn);
	ZKW(S,T);
//	cout<<"Maxn: "<<Maxn<<endl;
//	cout<<"Flow: "<<Flow<<endl;
//	cout<<"Cost: "<<Cost<<endl;
	puts(Flow==Sum&&Maxn==Sum-Cost?"YES":"NO");
	return 0;
}
