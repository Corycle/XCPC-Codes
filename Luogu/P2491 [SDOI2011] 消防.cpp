/*========Corycle========*/
#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=3e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,S,T,cnt,pos,Max,tot;
int h[N],L[N],q[N],f[N],f1[N],f2[N],pre[N],vst[N],dis[N];
struct edge{int to,next,dist;}d[N*2];
void Add(int x,int y,int z){d[++cnt]=(edge){y,h[x],z};h[x]=cnt;}
void DFS1(int x,int fa,int dist){
	dis[x]=dist;
	if(dist>Max){Max=dist;pos=x;}
	for(int i=h[x];i;i=d[i].next){
		int y=d[i].to;
		if(y==fa)continue;
		pre[y]=x;
		DFS1(y,x,dist+d[i].dist);
	}
}
int DFS2(int x,int fa){
	int tmp=0;
	for(int i=h[x];i;i=d[i].next){
		int y=d[i].to;
		if(y==fa||vst[y])continue;
		tmp=max(tmp,DFS2(y,x)+d[i].dist);
	}
	return tmp;
}
void GetLine(){
	for(int i=T;;i=pre[i]){vst[i]=1;L[++tot]=i;if(i==S)break;}
	reverse(L+1,L+tot+1);
	for(int i=1;i<=tot;i++)f[L[i]]=DFS2(L[i],0);
//	cout<<"========"<<endl;
//	for(int i=1;i<=tot;i++)cout<<L[i]<<" ";cout<<endl;
//	for(int i=1;i<=tot;i++)cout<<dis[L[i]]<<" ";cout<<endl;
}
int Solve(){
	int l=1,r=0,Ans=inf;f1[0]=inf;f2[tot+1]=-inf;
	for(int i=1;i<=tot;i++)f1[i]=min(f1[i-1],dis[L[i]]-f[L[i]]);
	for(int i=tot;i>=1;i--)f2[i]=max(f2[i+1],dis[L[i]]+f[L[i]]);
//	for(int i=1;i<=tot;i++)cout<<f1[i]<<" ";cout<<endl;
//	for(int i=1;i<=tot;i++)cout<<f2[i]<<" ";cout<<endl;
	q[++r]=1;
	for(int i=1,j=1;i<=tot;i++){
		while(l<=r&&q[l]<i)l++;
		while(j<tot&&dis[L[j+1]]-dis[L[i]]<=m){
			j++;
			while(l<=r&&f[L[q[r]]]<=f[L[j]])r--;
			q[++r]=j;
		}
		Ans=min(Ans,max(max(dis[L[i]]-f1[i],f2[j]-dis[L[j]]),f[L[q[l]]]));
	}
	return Ans;
}
int main(){
	n=read();m=read();
	for(int i=1;i<n;i++){int x=read(),y=read(),z=read();Add(x,y,z);Add(y,x,z);}
	Max=-1;DFS1(1,0,0);S=pos;
	Max=-1;DFS1(S,0,0);T=pos;
	GetLine();
	printf("%d\n",Solve());
	return 0;
}
