/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=5005;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,Mod,f[N],g[N],g2[N],C[N][N],P[N];
void Prepare(){
	P[0]=1;
    for(int i=1;i<N;i++)P[i]=2ll*P[i-1]%Mod;
    for(int i=0;i<N;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
    }
}
int Pow(int x,int y){int ans=1;while(y){if(y&1)ans=1ll*ans*x%Mod;x=1ll*x*x%Mod;y>>=1;}return ans;}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
    n=read();m=read();Mod=read();
	Prepare();
    int ans=0;
    for(int i=0;i<=n;i++){
        
    }
    printf("%d\n",ans);
	return 0;
}
