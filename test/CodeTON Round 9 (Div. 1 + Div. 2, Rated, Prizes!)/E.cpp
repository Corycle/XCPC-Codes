/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int Mod=998244353;
const int N=1e6+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,a[N],f[N],sum1[N],sum2[N],ans[N];
void Prepare(){
    for(int i=4;i<N;i++){
        f[i]=(1ll*i*(i-3)/2)%Mod;
        f[i]=(f[i]+sum1[i-1])%Mod;
        sum1[i]=(sum1[i-1]+1ll*i*f[i])%Mod;
        sum2[i]=(sum2[i-1]+f[i])%Mod;
        ans[i]=(f[i]+sum2[i-1])%Mod;
    }
    ans[2]=1;
    for(int i=3;i<N;i++){
        ans[i]=(ans[i]+i-1)%Mod;
    }
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
    Prepare();
    int T=read();
    while(T--){
        n=read();
        printf("%d\n",ans[n]);
    }
	return 0;
}
