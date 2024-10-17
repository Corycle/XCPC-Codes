#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=10005;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,K,id[N];
ll f[N];
struct Node{
    int v,c;
}a[N];
bool cmp(Node A,Node B){return A.c<B.c;}
bool cmp2(int x,int y){return a[x].v>a[y].v;}
int main(){
    n=read();m=read();K=read();
    for(int i=1;i<=n;i++){
        a[i].c=read();
        a[i].v=read();
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)id[i]=i;
    sort(id+1,id+n+1,cmp2);
    ll Ans=0;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=a[i].c;j--){
            f[j]=max(f[j],f[j-a[i].c]+a[i].v);
        }
        int num=min(K,n-i);
        ll ans=0;
        for(int j=1;j<=n;j++){
            if(id[j]<=i)continue;
            if(num){
                ans+=a[id[j]].v;
                num--;
            }
        }
        Ans=max(Ans,ans+f[m]);
    }
    printf("%lld\n",Ans);
    return 0;
}