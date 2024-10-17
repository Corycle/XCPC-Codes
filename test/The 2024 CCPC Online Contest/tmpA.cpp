#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int M=7;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int vst[N];
int n,m,num;
bool a[M][M];
unordered_map<ll,bool>vis;
ll Hash(bool c[][M]){
	ll res=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)res=(res<<1)|c[i][j];
	return res;
}
void Solve(bool c[][M]){
	ll x=Hash(c);
	if(vis[x])return;
	vis[x]=1;num++;
	bool d[M][M]={0};
	int num1[M]={0},num2[M]={0};
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){num1[i]+=c[i][j];num2[j]+=c[i][j];}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)d[i][j]=(j<=num1[i]);
	Solve(d);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)d[i][j]=(j>=m-num1[i]+1);
	Solve(d);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)d[i][j]=(i<=num2[j]);
	Solve(d);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)d[i][j]=(i>=n-num2[j]+1);
	Solve(d);
}
void Print(){
	if(vst[num])return;
	vst[num]=1;
	puts("============");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			putchar(a[i][j]?'*':'.');
		}
		puts("");
	}
	printf("Ans: %d\n",num);
}
void Check(){
	vis.clear();
	num=0;
	Solve(a);
	Print();
}
void DFS(int x,int y){
	if(y==m+1){DFS(x+1,1);return;}
	if(x==n+1){Check();return;}
	a[x][y]=1;
	DFS(x,y+1);
	a[x][y]=0;
	DFS(x,y+1);
}
int main(){
	freopen("5x6.out","w",stdout);
	n=5;m=6;
	DFS(1,1);
	return 0;
}
