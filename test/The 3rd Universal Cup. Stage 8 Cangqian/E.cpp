#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=65;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
ll sta[N];
int n,m,w[N];
struct Node{int l,r;}P[N];
unordered_map<ll,int>f[N],vis[N];
bool cmp(int x,int y){return P[x].r<P[y].r;}
int main(){
    n=read();
    for(int i=1;i<=n;i++){
        sta[i]=(1ll<<(i-1));
        P[i].l=read();P[i].r=read();
    }
    for(int i=1;i<=n;i++)w[i]=read();
    f[0][0]=0;
    vis[0][0]=1;
    for(int j=1;j<=n;j++){
        for(int i=j;i<=n;i++){
            for(auto x:f[i-j]){
                vector<int>S;
                for(int k=1;k<=n;k++){
                    if(x.first&sta[k])continue;
                    if(P[k].r<j||P[k].l>j)continue;
                    S.push_back(k);
                }
                if(S.size()<j)continue;
                sort(S.begin(),S.end(),cmp);
                int Sta=x.first;
                for(int k=0;k<j;k++)Sta|=sta[S[k]];
                if(!vis[i][Sta]){
                    vis[i][Sta]=1;
                    f[i][Sta]=-inf;
                }
                f[i][Sta]=max(f[i][Sta],x.second+w[j]);
            }
        }
    }
    if(!vis[n][(1ll<<n)-1])puts("impossible");
    else printf("%d\n",f[n][(1ll<<n)-1]);
    return 0;
}