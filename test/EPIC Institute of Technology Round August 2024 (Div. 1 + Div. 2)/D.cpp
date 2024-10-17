/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=3e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,num,a[N],fa[N],sum[N],pos[N],vis[N];
vector<int>G[N];
multiset<int>S[N];
//pos[x]<=pos[y]<=pos[i]+sum[i]-1
void DFS(int x){
    sum[x]=1;
    for(auto y:G[x]){
        DFS(y);
        sum[x]+=sum[y];
    }
}
int Check(int x){
    if(G[x].empty())return 1;
    return pos[x]<=(*S[x].begin())&&(*(--S[x].end()))<=pos[x]+sum[x]-1;
}
void Clear(){
    num=0;
    for(int i=1;i<=n;i++){
        a[i]=0;
        pos[i]=0;
        fa[i]=0;
        sum[i]=0;
        G[i].clear();
        S[i].clear();
    }
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
    int T=read();
    while(T--){
        n=read();m=read();
        for(int i=2;i<=n;i++){
            G[fa[i]=read()].push_back(i);
        }
        DFS(1);
        for(int i=1;i<=n;i++){
            int x=a[i]=read();
            pos[x]=i;
            if(fa[x]){
                S[fa[x]].insert(pos[x]);
                S[fa[x]].insert(pos[x]+sum[x]-1);
            }
        }
        for(int i=1;i<=n;i++){
            num+=Check(i);
            vis[i]=1;
        }
        for(int i=1;i<=m;i++){
            int p1=read(),p2=read();
            int x=a[p1],y=a[p2];

            if(vis[x]){num-=Check(x);vis[x]=0;}
            if(vis[y]){num-=Check(y);vis[y]=0;}
            if(fa[x]&&vis[fa[x]]){num-=Check(fa[x]);vis[fa[x]]=0;}
            if(fa[y]&&vis[fa[y]]){num-=Check(fa[y]);vis[fa[y]]=0;}

            if(fa[x]){
                S[fa[x]].erase(S[fa[x]].find(pos[x]));
                S[fa[x]].erase(S[fa[x]].find(pos[x]+sum[x]-1));
            }
            if(fa[y]){
                S[fa[y]].erase(S[fa[y]].find(pos[y]));
                S[fa[y]].erase(S[fa[y]].find(pos[y]+sum[y]-1));
            }

            swap(pos[x],pos[y]);
            swap(a[p1],a[p2]);

            if(fa[x]){
                S[fa[x]].insert(pos[x]);
                S[fa[x]].insert(pos[x]+sum[x]-1);
            }
            if(fa[y]){
                S[fa[y]].insert(pos[y]);
                S[fa[y]].insert(pos[y]+sum[y]-1);
            }

            if(!vis[x]){num+=Check(x);vis[x]=1;}
            if(!vis[y]){num+=Check(y);vis[y]=1;}
            if(fa[x]&&!vis[fa[x]]){num+=Check(fa[x]);vis[fa[x]]=1;}
            if(fa[y]&&!vis[fa[y]]){num+=Check(fa[y]);vis[fa[y]]=1;}

            puts(num==n?"YES":"NO");
        }
        Clear();
    }
	return 0;
}
