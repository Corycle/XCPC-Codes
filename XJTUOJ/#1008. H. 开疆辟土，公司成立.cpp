/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=5e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,cnt,Ans,fa[N];
struct edge{int x,y,dist;}e[N];
inline int id(int x,int y){return (x-1)*m+y;}
bool cmp(edge A,edge B){return A.dist>B.dist;}
int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
void Kruskal(){
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=n*m;i++)fa[i]=i;
	for(int i=1;i<=cnt;i++){
		int x=Find(e[i].x),y=Find(e[i].y);
		if(x==y)continue;
		fa[x]=y;Ans-=e[i].dist;
	}
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
	while(T--){
		n=read();m=read();cnt=Ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				int x=read(),y=read();Ans+=x+y;
				if(i!=n)e[++cnt]=(edge){id(i,j),id(i+1,j),x};
				if(j!=m)e[++cnt]=(edge){id(i,j),id(i,j+1),y};
			}
		}
		Kruskal();
		printf("%d\n",Ans);
	}
	return 0;
}
