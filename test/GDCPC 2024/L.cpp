#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,a[N],f1[N],f2[N],g1[N],g2[N],pos;
ll sum[N],ans,sum2[N];
vector<int>G[N];
void DFS1(int x,int fa){
    for(auto y:G[x]){
        if(y==fa)continue;
        DFS1(y,x);
        if(a[y]>=a[f1[x]]){f2[x]=f1[x];f1[x]=y;}
        else if(a[y]>=a[f2[x]])f2[x]=y;
    }
    sum[x]=sum[f1[x]]+a[x];

    if(sum[x]>ans){ans=sum[x];pos=x;}
    else if(sum[x]==ans)pos=min(pos,x);

    g1[x]=f1[x];g2[x]=f2[x];sum2[x]=sum[x];
}
void DFS2(int x,int fa){
    if(fa){
        if(f1[fa]==x){
            f1[fa]=f2[fa];
            sum[fa]=sum[f1[fa]]+a[fa];
        }
        f1[x]=f2[x]=0;
        for(auto y:G[x]){
            if(a[y]>=a[f1[x]]){f2[x]=f1[x];f1[x]=y;}
            else if(a[y]>=a[f2[x]])f2[x]=y;
        }
        sum[x]=sum[f1[x]]+a[x];
        if(sum[x]>ans){ans=sum[x];pos=x;}
        else if(sum[x]==ans)pos=min(pos,x);
    }
    int tmp1=f1[x],tmp2=f2[x];
    ll tmp3=sum[x];
    // cout<<x<<" : "<<f1[x]<<" "<<f2[x]<<" "<<sum[x]<<endl;
    // for(int i=1;i<=n;i++)cout<<sum[i]<<" ";cout<<endl;
    for(auto y:G[x]){
        if(y==fa)continue;
        DFS2(y,x);
        f1[x]=tmp1;f2[x]=tmp2;sum[x]=tmp3;
    }
    f1[x]=g1[x];f2[x]=g2[x];sum[x]=sum2[x];
}
int main(){
    n=read();
    for(int i=2;i<=n;i++){
        int x=read();
        G[i].push_back(x);
        G[x].push_back(i);
    }
    for(int i=1;i<=n;i++)a[i]=read();
    DFS1(1,0);
    DFS2(1,0);
    printf("%d\n%lld",pos,ans);
    return 0;
}