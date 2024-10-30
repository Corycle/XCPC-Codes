#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
using namespace std;
const int N=1e6+5;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;c
}
int n,a[N];
set<int> s;
map<pii,bool>vis;
void DFS(int x,int y){
    if(vis[make_pair(x,y)])return;
    vis[make_pair(x,y)]=1;
    s.insert(x);s.insert(y);
    DFS(x,x&y);
    DFS(x,x|y);
    DFS(x,x^y);
}
int main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<n;++i){
        DFS(a[i],a[i+1]);
    }
    printf("%d\n",(int)s.size());
    return 0;
}