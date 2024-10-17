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
int F(int n,int K){
    if(K<=31&&n>=(1<<K)-1)return (1<<K);
    int ans=1;
    for(int i=0;i<K&&(1<<i)<=n;i++){
        if(n>=(1<<(i+1))-1)ans+=(1<<i);
        else ans+=F(n-(1<<i),K);
    }
    return ans;
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
    while(T--){
        int n=read(),K=read();
        printf("%d\n",F(n,K));
    }
	return 0;
}
