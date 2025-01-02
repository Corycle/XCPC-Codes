/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=4e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
ll ans;
int n,Root,vis[N],sum[N];
vector<int>G[N];
void DFS1(int x,int fa){
    sum[x]=(vis[x]==0);
    for(auto y:G[x]){
        if(y==fa)continue;
        DFS1(y,x);
        sum[x]+=sum[y];
    }
}
void DFS2(int x,int fa){
    for(auto y:G[x]){
        if(y==fa)continue;
        DFS2(y,x);
        if(vis[y]==2){
            ans+=sum[y];
        }
    }
    if(fa&&vis[x]!=1&&vis[fa]==2){
        ans+=sum[Root]-sum[x];
    }
}
void Clear(){
    for(int i=1;i<=n;i++){
        G[i].clear();
        vis[i]=0;
        sum[i]=0;
    }
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
    while(T--){
        ans=0;Root=0;
        n=read();
        for(int i=1;i<n;i++){
            int x=read(),y=read();
            G[x].push_back(y);
            G[y].push_back(x);
        }
        if(n==2){puts("0");Clear();continue;}
        int num=0;
        for(int i=1;i<=n;i++){
            if(G[i].size()==1){
                num++;
                vis[G[i][0]]=2;
                vis[i]=1;
            }
        }
        ans+=1ll*num*(n-num);
        for(int i=1;i<=n;i++){
            if(G[i].size()!=1){
                Root=i;break;
            }
        }
        DFS1(Root,0);
        DFS2(Root,0);
        printf("%lld\n",ans);
        Clear();
    }
	return 0;
}
