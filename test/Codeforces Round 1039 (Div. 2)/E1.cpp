#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,a[N],ans,L,R,b[N],sum[N];
bool Check(int v){
    for(int i=1;i<=n;i++){
        b[i]=(a[i]>=v?1:-1);
    }
    int Min=n,pos=0;
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+b[i];
        if(i>=m){
            if(Min>sum[i-m]){
                Min=sum[i-m];
                pos=i-m;
            }
            if(sum[i]-Min>=0){
                if(v>ans){
                    ans=v;L=pos+1;R=i;
                    return true;
                }
            }
        }
    }
    return false;
}
signed main(){
    int T=read();
    while(T--){
        n=read();m=read();
        for(int i=1;i<=n;i++)a[i]=read();
        if(m==1){
            int Max=0;
            for(int i=1;i<=n;i++){
                Max=max(Max,a[i]);
            }
            for(int i=1;i<=n;i++){
                if(Max==a[i]){
                    printf("%lld %lld %lld\n",Max,i,i);
                    break;
                }
            }
            continue;
        }
        int Min=n+1,Max=0;
        for(int i=1;i<=n;i++){
            Min=min(Min,a[i]);
            Max=max(Max,a[i]);
        }
        int l=Min,r=Max;
        ans=0;L=0;R=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(Check(mid)){
                l=mid+1;
            }
            else r=mid-1;
        }
        printf("%lld %lld %lld\n",ans,L,R);
    }
    return 0;
}