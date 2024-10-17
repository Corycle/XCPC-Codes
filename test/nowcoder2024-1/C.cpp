/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int Mod=1e9+7;
const int N=5e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,Ans,a[N];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
    int T=read();
    while(T--){
        int t=read(),v=read();
        for(int i=1;i<=t;i++){
            Ans=(Ans-1ll*n*a[n]%Mod+Mod)%Mod;
            n--;
        }
        a[++n]=v;
        Ans=(Ans+1ll*n*a[n])%Mod;
        printf("%d\n",Ans);
    }
	return 0;
}
