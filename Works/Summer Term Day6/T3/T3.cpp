/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1005;
const int M=N*N;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,a[N][N],fa[M],sum[M];
int id(int x,int y){return (x-1)*n+y;}
int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
void Union(int x,int y){
    x=Find(x);y=Find(y);
    if(x!=y){fa[x]=y;sum[y]+=sum[x];}
}
int main(){
	// freopen("T3_15.in","r",stdin);
	// freopen("T3_15.out","w",stdout);
	n=read();
    for(int i=1;i<=n*n;i++){fa[i]=i;sum[i]=1;}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=read();
            if(i!=1&&a[i][j]==a[i-1][j])Union(id(i,j),id(i-1,j));
            if(j!=1&&a[i][j]==a[i][j-1])Union(id(i,j),id(i,j-1));
        }
    }
    int Ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=1&&a[i][j]!=a[i-1][j])Ans=max(Ans,sum[Find(id(i,j))]+sum[Find(id(i-1,j))]);
            if(j!=1&&a[i][j]!=a[i][j-1])Ans=max(Ans,sum[Find(id(i,j))]+sum[Find(id(i,j-1))]);
        }
    }
    printf("%d\n",Ans);
	return 0;
}
