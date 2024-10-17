/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int Mod=998244353;
const int N=1e5+5;
const int M=6;
ll read(){
	ll s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
ll n;
int K,Ans,t[4],f[N][M];
int main(){
    n=read();K=read();
    for(int i=0;i<4;i++)t[i]=read();
    f[0][K]=1;
    for(int i=1;i<=n;i++){
        int Type=t[(i-1)%4];
        if(Type==1){
            for(int j=0;j<=5;j++)f[i][min(j+1,5)]=(f[i][min(j+1,5)]+f[i-1][j])%Mod;
        }
        if(Type==2){
            f[i][1]=(f[i][1]+f[i-1][0])%Mod;
            for(int j=1;j<=5;j++)f[i][j-1]=(f[i][j-1]+f[i-1][j])%Mod;
        }
        if(Type==3){
            for(int j=0;j<=5;j++)f[i][min(j+1,5)]=(f[i][min(j+1,5)]+f[i-1][j])%Mod;
            for(int j=1;j<=5;j++)f[i][j-1]=(f[i][j-1]+f[i-1][j])%Mod;
        }
    }
    for(int i=0;i<=5;i++)Ans=(Ans+f[n][i])%Mod;
    printf("%d\n",Ans);
	return 0;
}
