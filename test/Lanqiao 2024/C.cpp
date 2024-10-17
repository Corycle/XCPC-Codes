#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll read(){
	ll s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
ll n,S,sum,ans,sumP,MaxC,p[N],c[N],b[N];
int main(){
	n=read();S=read();
	for(int i=1;i<=n;i++){
		p[i]=read();c[i]=read();
		sum+=p[i]*c[i];
		MaxC=max(MaxC,c[i]);
		b[c[i]]+=p[i];
		sumP+=p[i];
	}
	ans=sum;
	for(int i=1;i<=MaxC;i++){
		sum=sum-sumP+S;
		ans=min(ans,sum);
		sumP-=b[i];
	}
	printf("%lld\n",ans);
	return 0;
}
