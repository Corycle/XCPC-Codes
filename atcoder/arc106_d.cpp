/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int Inv2=499122177;
const int Mod=998244353;
const int N=2e5+5;
const int M=305;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,K,a[N],f[M],p[M],C[M][M];
int mod(int x){return x>=Mod?x-Mod:x;}
void Prepare(){
    C[0][0]=p[0]=1;
    for(int i=1;i<M;i++){
        C[i][0]=1;
        p[i]=mod(p[i-1]<<1);
        for(int j=1;j<=i;j++)C[i][j]=mod(C[i-1][j-1]+C[i-1][j]);
    }
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();K=read();Prepare();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++){
        int p=1;
        for(int j=0;j<=K;j++){
            f[j]=mod(f[j]+p);
            p=1ll*p*a[i]%Mod;
        }
    }
    for(int k=1;k<=K;k++){
        int ans=0;
        for(int j=0;j<=k;j++)ans=mod(ans+1ll*C[k][j]*f[j]%Mod*f[k-j]%Mod);
        ans=1ll*mod(ans-1ll*p[k]*f[k]%Mod+Mod)*Inv2%Mod;
        printf("%d\n",ans);
    }
	return 0;
}
