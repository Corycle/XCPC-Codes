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
int n,m,a[N],f[N],g[N],sum[N];
signed main(){
    int T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++){
            a[i]=read();
            if(i==1){
                f[i]=1;
                g[i]=1;
            }
            else if(i==2){
                if(a[1]>a[2]){
                    f[i]=2;
                    g[i]=3;
                }
                else{
                    f[i]=2;
                    g[i]=2;
                }
            }
            else {
                if(a[i-2]>a[i] && a[i]>a[i-1]){
                    g[i]=g[i-2]+f[i-2]+2;
                    f[i]=f[i-2]+2;
                }
                else if(a[i-2]>a[i-1] && a[i-1]>a[i]){
                    g[i]=g[i-1]+f[i-1]+1;
                    f[i]=f[i-1]+1;
                }
                else if(a[i-1]>a[i] && a[i]>a[i-2]){
                    g[i]=g[i-1]+f[i-1]+1;
                    f[i]=f[i-1]+1;
                }
                else if(a[i-1]>a[i-2] && a[i-2]>a[i]){
                    g[i]=g[i-2]+f[i-2]+3;
                    f[i]=f[i-2]+2;
                }
            }
            // cout<<"f[i]="<<f[i]<<" g[i]="<<g[i]<<endl;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=g[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}