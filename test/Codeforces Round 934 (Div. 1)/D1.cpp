/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
const int N=405;
int n,K,Mod;
int f[2][N][N];
int mod(int x){return x>=Mod?x-Mod:x;}
void Main(){
    int T=read();
    while(T--){
        n=read();K=read();Mod=read();
        for(int i=0;i<=K;i++)for(int j=0;j<=K;j++)f[0][i][j]=f[1][i][j]=0;
        int t=0;
        f[t][0][0]=1;
        for(int i=1;i<=n+1;i++){
            t^=1;
            for(int j=0;j<=K;j++)for(int k=0;k<=K;k++)f[t][j][k]=0;
            for(int j=0;j<=K;j++){
                for(int k=0;k<=K;k++){
                    if(!f[t^1][j][k])continue;
                    //a[i]<=j-k
                    f[t][max(j-k,0)][j]=mod(f[t][max(j-k,0)][j]+f[t^1][j][k]);
                }
            }
            for(int l=1;l<=K;l++){
                for(int j=0;j<=K;j++){
                    f[t][l][j]=mod(f[t][l][j]+f[t][l-1][j]);
                }
            }
        }
        int Ans=0;
        for(int i=0;i<=K;i++)Ans=mod(Ans+f[t][0][i]);
        printf("%d\n",Ans);
    }
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
    Main();
	return 0;
}
