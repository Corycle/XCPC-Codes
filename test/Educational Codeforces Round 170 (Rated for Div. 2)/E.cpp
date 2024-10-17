#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
const int N=505;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,f[N][N],fac[N],inv[N];
int C(int n,int m){return 1ll*fac[n]*inv[m]%Mod*inv[n-m]%Mod;}
int main(){
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<N;i++)fac[i]=1ll*fac[i-1]*i%Mod;
    for(int i=2;i<N;i++)inv[i]=1ll*inv[Mod%i]*(Mod-Mod/i)%Mod;
    for(int i=2;i<N;i++)inv[i]=1ll*inv[i-1]*inv[i]%Mod;
    n=read();m=read();
    /*
        f[i][j] i~n已确定，有j个没解决的牌
    */
    f[n+1][0]=1;
    for(int i=n;i>=2;i--){
        for(int k=0;k*2<=m;k++){
            /*
                k个')',m-k个'('
                (0,0)->(k,m-k)
                (1,-1)->(k,m-k)
            */
            int res=(k?(C(m,k)-C(m,k-1)+Mod)%Mod:1);
            // cout<<i<<": "<<k<<" :"<<res<<endl;
            for(int j=m-k*2;j<=m;j++){
                f[i][j]=(f[i][j]+1ll*f[i+1][j-(m-k*2)]*res)%Mod;
            }
        }
        // for(int j=0;j<=m;j++)printf("%d ",f[i][j]);puts("");
    }
    int ans=0;
    for(int i=0;i<=m;i++){
        /*
            i+m个
            numA+numB=m
            numA-numB=i
            numA=(m+i)/2
            numB=m-numA;
            前面i个'(', 
            (0,i)->(numA,numA)
            (i+1,-1)->(numA,numA)
        */
        if((m+i)&1)continue;
        int A=(m+i)/2;
        ans=(ans+1ll*(C(A*2-i,A)-C(A*2-i,A+1)+Mod)%Mod*f[2][i])%Mod;
    }
    printf("%d\n",ans);
    return 0;
}