#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int inf=0x3f3f3f3f;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,cnt,a[N],vis[N],prime[N],f[N][4];
void Prepare(){
    vis[1]=1;
    for(int i=1;i<N;i++){
        if(!vis[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&1ll*i*prime[j]<N;j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int Check(int x){return vis[x]==0;}
int main(){
    Prepare();
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    memset(f,0x3f,sizeof(f));
    f[1][0]=0;f[1][1]=f[1][2]=f[1][3]=1;
    for(int i=2;i<=n;i++){
        if(a[i]&1){
            f[i][0]=min(f[i][0],f[i-1][2]);
            if(Check(a[i]+a[i-1]))f[i][0]=min(f[i][0],f[i-1][0]);
            if(Check(a[i]+1))f[i][0]=min(f[i][0],f[i-1][3]);
        }
        else{
            f[i][0]=min(f[i][0],f[i-1][1]);
            if(Check(a[i]+a[i-1]))f[i][0]=min(f[i][0],f[i-1][0]);
            if(Check(a[i]+1))f[i][0]=min(f[i][0],f[i-1][3]);
        }
        if(a[i-1]%2==0)f[i][1]=min(f[i][1],1+f[i-1][0]);
        f[i][1]=min(f[i][1],1+f[i-1][2]);
        
        if(a[i-1]%2==1)f[i][2]=min(f[i][2],1+f[i-1][0]);
        f[i][2]=min(f[i][2],1+f[i-1][1]);
        f[i][2]=min(f[i][2],1+f[i-1][3]);

        if(Check(a[i-1]+1))f[i][3]=min(f[i][3],1+f[i-1][0]);
        f[i][3]=min(f[i][3],1+f[i-1][2]);
        f[i][3]=min(f[i][3],1+f[i-1][3]);
    }
    int ans=inf;
    for(int i=0;i<=3;i++)ans=min(ans,f[n][i]);
    printf("%d\n",ans);
    return 0;
}