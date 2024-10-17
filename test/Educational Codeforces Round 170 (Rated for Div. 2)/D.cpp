#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
const int N=2e6+5;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,num,a[N],f[N],sum[N];
int main(){
    n=read();m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        if(!a[i]){
            //f[i][j]=max(f[i-1][j],f[i-1][j-1])
            num++;
            for(int j=1;j<=m;j++)sum[j]+=sum[j-1];
            for(int j=0;j<=m;j++)f[j]+=sum[j];
            for(int j=m;j>=1;j--)f[j]=max(f[j],f[j-1]);
            for(int j=0;j<=m;j++)sum[j]=0;
        }
        else if(a[i]>0){
            //f[i][j]++;(j>=a[i])
            if(a[i]<=num){
                sum[a[i]]++;
                sum[num+1]--;
            }
        }
        else{
            //f[i][j]++;(num-j>=-a[i],j<=num+a[i])
            if(num+a[i]+1>=0){
                sum[0]++;
                sum[num+a[i]+1]--;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=m;i++)sum[i]+=sum[i-1];
    for(int i=0;i<=m;i++){
        f[i]+=sum[i];
        ans=max(ans,f[i]);
    }
    printf("%d\n",ans);
    return 0;
}