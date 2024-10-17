/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=3005;
const int M=20005;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int cnt,h[N],vis[N][N],vst[N];
struct edge{int to,next;}d[M];
void Add(int x,int y){d[++cnt]=(edge){y,h[x]};h[x]=cnt;}
int Rand(int Maxn){return (rand()*rand()+rand())%Maxn+1;}
void DFS(int x){
    vst[x]=1;
    for(int i=h[x];i;i=d[i].next){
        int y=d[i].to;
        if(!vst[y])DFS(y);
    }
}
int main(){
	freopen("graph20.in","w",stdout);
	srand(time(NULL));
	int n=2000-Rand(1e2);
    int m=10000-Rand(1e3);
    // int n=50,m=100;
    int MaxE=1e5;
    printf("%d %d\n",n,m);
    for(int i=2;i<=n;i++){
        int x=Rand(i-1);
        while(abs(x-i)>40)x=Rand(i-1);
        printf("%d %d %d\n",x,i,Rand(MaxE));
        Add(x,i);
        vis[x][i]=vis[i][x]=1;
    }
    for(int i=n;i<=m;i++){
        int x=Rand(n),y=Rand(n);
        // while(x==y||vis[x][y]){x=Rand(n);y=Rand(n);}
        while(x==y||vis[x][y]||abs(x-y)>40){x=Rand(n);y=Rand(n);}
        if(x>y)swap(x,y);
        printf("%d %d %d\n",x,y,Rand(MaxE));
        Add(x,y);
        vis[x][y]=vis[y][x]=1;
    }
    DFS(1);
    for(int i=1;i<=n;i++)if(!vst[i]){cerr<<"Error!"<<endl;return 0;}
    cerr<<"Success!"<<endl;
	return 0;
}
