#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1000006;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,ans[N],vis[N];
pair<int,int> a[1000006];
int main(){
    n=read();
    for(int i=1;i<=n;++i) 
    {
        int x=read();
        if(x!=1&&!vis[x-1]){
            puts("-1");
            return 0;
        }
        vis[x]=true;
        a[i]=make_pair(x,-i);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i) ans[-a[i].second]=i;
    for(int i=1;i<=n;++i) printf("%d ",ans[i]);
}