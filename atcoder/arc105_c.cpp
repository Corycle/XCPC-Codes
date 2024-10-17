/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int STA=1<<8;
const int N=1e5+5;
const int M=10;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,Ans;
int a[M],b[M],p[M],f[M],vis[M],g[STA];
struct Bridge{int l,w;}P[N];
bool cmp(Bridge A,Bridge B){return A.w!=B.w?A.w<B.w:A.l>B.l;}
void DFS(int x){
    if(x==n+1){
        f[0]=0;
        for(int i=1;i<=n;i++){
            int S=p[b[i]];f[i]=0;
            for(int j=i-1;j>=1;j--){
                S|=p[b[j]];
                f[i]=max(f[i],f[j]+g[S]);
            }
        }
        Ans=min(Ans,f[n]);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;b[x]=i;
            DFS(x+1);
            vis[i]=0;b[x]=0;
        }
    }
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();m=read();Ans=inf;
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=m;i++){P[i].l=read();P[i].w=read();}
    sort(a+1,a+n+1);
    sort(P+1,P+m+1,cmp);
    int MinW=P[1].w,MaxA=a[n],Sta=1<<n;
    if(MaxA>MinW){puts("-1");return 0;}
    for(int i=1;i<=n;i++)p[i]=1<<(i-1);
    for(int S=1;S<=Sta;S++){
        int sum=0;
        for(int i=1;i<=n;i++)if(S&p[i])sum+=a[i];
        for(int i=1;i<=m;i++)g[S]=max(g[S],P[i].l*(sum>P[i].w));
    }
    DFS(1);
    printf("%d\n",Ans);
	return 0;
}
