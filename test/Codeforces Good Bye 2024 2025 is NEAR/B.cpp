/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=5e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,L[N],R[N],cnt[N],sum[N];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n*2;i++)cnt[i]=sum[i]=0;
        for(int i=1;i<=n;i++){
            L[i]=read();R[i]=read();
            if(L[i]==R[i])cnt[L[i]]++;
        }
        for(int i=1;i<=n*2;i++)sum[i]=sum[i-1]+(cnt[i]!=0);
        for(int i=1;i<=n;i++){
            if(L[i]==R[i])putchar(cnt[L[i]]>1?'0':'1');
            else putchar(sum[R[i]]-sum[L[i]-1]==R[i]-L[i]+1?'0':'1');
        }
        puts("");
    }
	return 0;
}
