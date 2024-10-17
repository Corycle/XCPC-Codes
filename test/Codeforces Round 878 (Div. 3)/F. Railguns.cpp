/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=20005;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,q;
bool vis[2][N],b1[N],b2[N];
struct Node{int t,op,x;}a[N];
int id(int x,int y){return (x-1)*m+y;}
bool cmp(Node x,Node y){return x.t<y.t;}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
    while(T--){
        n=read()+1;m=read()+1;q=read();
        for(int i=1;i<=q;i++){
            a[i].t=read();
            a[i].op=read();
            a[i].x=read()+1;
        }
        sort(a+1,a+q+1,cmp);
        memset(vis,0,sizeof(vis));
        vis[0][id(1,1)]=1;
        int p=1,K=0,ans=-1;
        for(int t=1;t<=q+n+m;t++){
            for(int i=1;i<=n;i++)b1[i]=0;
            for(int i=1;i<=m;i++)b2[i]=0;
            while(p<=q&&a[p].t==t){
                if(a[p].op==1)b1[a[p].x]=1;
                else b2[a[p].x]=1;
                p++;
            }
            memset(vis[K^1],0,sizeof(vis[K^1]));
            for(int x=1;x<=n;x++){
                for(int y=1;y<=m;y++){
                    if(!vis[K][id(x,y)])continue;
                    if(!b1[x]&&!b2[y])vis[K^1][id(x,y)]=1;
                    if(x!=n&&!b1[x+1]&&!b2[y])vis[K^1][id(x+1,y)]=1;
                    if(y!=m&&!b1[x]&&!b2[y+1])vis[K^1][id(x,y+1)]=1;
                }
            }
            if(vis[K^1][id(n,m)]){ans=t;break;}
            K^=1;
        }
        printf("%d\n",ans);
    }
	return 0;
}
