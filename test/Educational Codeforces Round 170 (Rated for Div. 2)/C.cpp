#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
const int N=2e5+5;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,a[N],b[N],cnt[N],sum[N];
int main(){
    int T=read();
    while(T--){
        n=read();m=read();
        for(int i=1;i<=n;i++)a[i]=b[i]=read();
        sort(b+1,b+n+1);
        b[0]=unique(b+1,b+n+1)-b-1;
        for(int i=1;i<=n;i++){
            a[i]=lower_bound(b+1,b+b[0]+1,a[i])-b;
            cnt[a[i]]++;
        }
        for(int i=1;i<=b[0];i++)sum[i]=sum[i-1]+cnt[i];
        int ans=0;
        for(int i=1,j=1;i<=b[0];i++){
            while(b[j]<b[i]-i+j||j<i-m+1)j++;
            ans=max(ans,sum[i]-sum[j-1]);
        }
        printf("%d\n",ans);
        for(int i=1;i<=b[0];i++)cnt[i]=0;
    }
    return 0;
}