#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,K,a[N],vis[N];
vector<int>Ans[N],G[N],S;
void BFS(int s){
    for(int i=1;i<=n;i++){vis[i]=0;}
    queue<int>q;q.push(s);vis[s]=1;
    while(q.size()){
        int x=q.front();q.pop();
        S.push_back(x);
        if(a[x])continue;
        for(auto y:G[x]){
            if(!vis[y]){
                vis[y]=1;
                q.push(y);
                Ans[x].push_back(y);
            }
        }
    }
}
int main(){
    n=read();m=read();K=read();
    for(int i=1;i<=K;i++)a[read()]=1;
    for(int i=1;i<=m;i++){
        int x=read(),y=read();
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!a[i]){
            BFS(i);
            break;
        }
    }
    int t=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){puts("No");return 0;}
        if(Ans[i].size())t++;
    }
    puts("Yes");
    printf("%d\n",t);
    for(auto x:S){
        if(Ans[x].empty())continue;
        printf("%d %d ",x,(int)Ans[x].size());
        for(auto y:Ans[x])printf("%d ",y);
        puts("");
    }
    return 0;
}