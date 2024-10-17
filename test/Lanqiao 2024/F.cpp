#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;
const int N=1e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,a[N],c[N];
ll n1[N],n2[N];
namespace Task1{
	void Main(){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int l=1;l<=n;l++){
						if(i==j||i==k||i==l||j==k||j==l||k==l)continue;
						if(a[k]%a[i]==0&&a[l]%a[j]==0)ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
}
namespace Task2{
	const ll Fac2=2;
	const ll Fac3=6;
	const ll Fac4=24;
	ll Cn2(ll x){return x*(x-1)/2;}
	ll Cn3(ll x){return x*(x-1)/2*(x-2)/3;}
	ll Cn4(ll x){return x*(x-1)/2*(x-2)/3*(x-3)/4;}
	void Prepare(){
		for(int i=1;i<N;i++){
			for(int j=i*2;j<N;j+=i){// i != j
				n1[i]+=c[j];
				n2[j]+=c[i];
			}
		}
	}
	ll Solve1(){
		ll ans=0;
		return ans;
	}
	ll Solve2(){
		ll ans=0;
		for(int i=1;i<N;i++)ans+=Cn3(c[i])*Fac3*(2*n1[i]+2*n2[i]);
		return ans;
	}
	ll Solve3(){
		ll ans=0;
		for(int i=1;i<N;i++)ans+=Cn4(c[i])*Fac4;
		return ans;
	}
	void Main(){
		Prepare();
		printf("%lld\n",Solve1()+Solve2()+Solve3());
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		c[a[i]]++;
	}
	sort(a+1,a+n+1);
	if(n<=50){Task1::Main();return 0;}
	Task2::Main();
	return 0;
}
