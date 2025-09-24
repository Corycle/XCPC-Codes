#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,popcnt,fma")
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,cnt,tot,a[N],id1[N],id2[N],dis[N],vis[N],h[N],H[N];
struct edge{int to,next,flow;}d[N];
void Add(int x,int y,int z){
	d[++cnt]=(edge){y,h[x],z};h[x]=cnt;
	d[++cnt]=(edge){x,h[y],0};h[y]=cnt;
}
bool BFS(int s,int t){
	for(int i=1;i<=tot;i++){dis[i]=-1;H[i]=h[i];}
	queue<int>q;q.push(s);dis[s]=0;
	while(q.size()){
		int x=q.front();q.pop();
		if(x==t)return true;
		for(int i=h[x];i;i=d[i].next){
			int y=d[i].to;
			if(d[i].flow&&dis[y]==-1){
				dis[y]=dis[x]+1;q.push(y);
			}
		}
	}
	return false;
}
int DFS(int x,int maxn,int t){
	if(x==t||!maxn)return maxn;
	int ans=0;
	for(int &i=H[x];i;i=d[i].next){
		int y=d[i].to;
		if(d[i].flow&&dis[y]==dis[x]+1){
			int dlt=DFS(y,min(maxn,d[i].flow),t);
			if(!dlt)dis[y]=-1;
			d[i].flow-=dlt;
			d[i^1].flow+=dlt;
			maxn-=dlt;ans+=dlt;
			if(!maxn)return ans;
		}
	}
	return ans;
}
int Dinic(int s,int t){
	int ans=0;
	while(BFS(s,t))ans+=DFS(s,inf,t);
	return ans;
}
bool Check(int x){
	cnt=1;tot=0;
	int S=++tot,T=++tot;
	for(int i=1;i<=3;i++)id1[i]=++tot;
	for(int i=1;i<=7;i++)id2[i]=++tot;
	for(int i=1;i<=tot;i++)h[i]=0;
	for(int i=1;i<=7;i++){
		Add(S,id2[i],a[i]);
		for(int j=1;j<=3;j++){
			if((i>>(j-1))&1){
				Add(id2[i],id1[j],inf);
			}
		}
	}
	for(int i=1;i<=3;i++)Add(id1[i],T,x);
	return Dinic(S,T)==x*3;
}
int main(){
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=7;i++)a[i]=read();
		int l=0,r=n/3,ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(Check(mid)){
				l=mid+1;
				ans=mid;
			}
			else r=mid-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
