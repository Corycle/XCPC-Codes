#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
vector<int>a[N];
int n,m,cnt,num,ans[N],h[N],deg[N];
struct edge{int to,next;}d[N];
void Add(int x,int y){d[++cnt]=(edge){y,h[x]};h[x]=cnt;}
void Solve(){
    num=0;
    priority_queue<int>q;
    for(int i=1;i<=n;i++)if(!deg[i])q.push(i);
    while(q.size()){
        int x=q.top();q.pop();ans[++num]=x;
        for(int i=h[x];i;i=d[i].next){
            int y=d[i].to;
            if(!(--deg[y]))q.push(y);
        }
    }
}
int main(){
    int T=read();
    while(T--){
        n=read();m=read();cnt=0;
        for(int i=1;i<=n;i++)h[i]=deg[i]=0;
        for(int i=1;i<=n;i++){
            int num=read();
            for(int j=1;j<=num;j++){
                a[read()].push_back(i);
            }
        }
        for(int i=1;i<=m;i++){
            int num=a[i].size();
            if(!num)continue;
            int lst=a[i][num-1];
            for(auto pos:a[i]){
                if(pos!=lst){
                    Add(pos,lst);
                    deg[lst]++;
                }
            }
        }
        Solve();
        int flag=0;
        for(int i=1;i<=n;i++)flag|=(ans[i]!=i);
        if(flag){
            puts("Yes");
            for(int i=1;i<=n;i++)printf("%d ",ans[i]);
            puts("");
        }
        else puts("No");
        for(int i=1;i<=m;i++)a[i].clear();
    }
    return 0;
}