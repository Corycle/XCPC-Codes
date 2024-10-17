/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=15;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,a[N][N];
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();
	int x=1,y=n,t=0;
	for(int i=1;i<=n;i++)a[i][0]=a[i][n+1]=a[0][i]=a[n+1][i]=-1;
	for(int i=1;i<=n*n;i++){
		a[x][y]=i;
		if(a[x+dx[t]][y+dy[t]])t=(t+1)%4;
		x+=dx[t];y+=dy[t];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)printf("%4d",a[i][j]);
		puts("");
	}
	return 0;
}
