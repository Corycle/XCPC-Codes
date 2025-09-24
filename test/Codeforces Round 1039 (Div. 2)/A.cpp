#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=105;
int a[N],b[N];
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=0;
        }
        int p=1,ans=0;
        for(int i=1;i<=n;i++){
            int t=0;
            for(int j=1;j<=n;j++){
                if(b[j])continue;
                if(a[j]*p<=m){
                    if(!t||a[j]>a[t])t=j;
                }
            }
            if(!t)ans++;
            else b[t]=1;
            p*=2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}