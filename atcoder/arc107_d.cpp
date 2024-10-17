/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int Mod=998244353;
const int N=3005;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,K,f[N][N];
int mod(int x){return x>=Mod?x-Mod:x;}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();K=read();f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            f[i][j]=mod(f[i-1][j-1]+f[i][min(j*2,N-1)]);
        }
    }
    printf("%d\n",f[n][K]);
	return 0;
}
