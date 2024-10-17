#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,a[N],f[N];
double b[N],sum[N];
ll B[N];
struct BIT{
    int c[N];
    int lowbit(int x){return x&(-x);}
    void Init(){for(int i=1;i<=n;i++)c[i]=0;}
    void Insert(int x,int y){for(;x<=n;x+=lowbit(x))c[x]=max(c[x],y);}
    int Query(int x){int ans=0;for(;x>=1;x-=lowbit(x))ans=max(ans,c[x]);return ans;}
}tree;
bool Check(double ave){
    tree.Init();
    for(int i=1;i<=n;i++){
        b[i]=a[i]-ave;
        sum[i]=sum[i-1]+b[i];
        B[i]=sum[i]*1e6;
    }
    sort(B+1,B+n+1);
    B[0]=unique(B+1,B+n+1)-B-1;
    // cout<<"Check: "<<ave<<endl;
    for(int i=1;i<=n;i++){
        ll x=sum[i]*1e6;
        x=lower_bound(B+1,B+B[0]+1,x)-B;
        f[i]=tree.Query(x)+1;
        if(sum[i]<0&&f[i]==1)f[i]=0;
        // cout<<f[i]<<" ";
        tree.Insert(x,f[i]);
    }
    // cout<<endl;
    return f[n]>=m;
}
int main(){
    n=read();m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    double l=0,r=1000;
    while(r-l>1e-6){
        double mid=(l+r)/2;
        if(Check(mid))l=mid;
        else r=mid;
    }
    printf("%.6lf\n",l);
    return 0;
}