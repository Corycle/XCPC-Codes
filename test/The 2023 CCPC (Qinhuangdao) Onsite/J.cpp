#include<bits/stdc++.h>
using namespace std;
int n,m,a[20],f[1<<13],sum[1<<13];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[x]++;
    }
    sort(a+1,a+13+1);
    reverse(a+1,a+13+1);
    for(int i=1;i<=13;i++)if(!a[i+1]){n=i;break;}
    int Sta=(1<<n)-1;
    for(int S=0;S<=Sta;S++){
        for(int i=1;i<=n;i++){
            if((S>>(i-1))&1)sum[S]+=a[i];
        }
    }
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    for(int S=1;S<=Sta;S++){
        for(int T=S;T!=0;T=(T-1)&S){
            if(sum[T]<=m)f[S]=min(f[S],f[S^T]+1);
        }
    }
    cout<<f[Sta]<<endl;
    return 0;
}