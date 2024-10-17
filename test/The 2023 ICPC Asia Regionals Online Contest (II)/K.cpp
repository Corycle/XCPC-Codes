#include<bits/stdc++.h>
#pragma GCC target("bmi,popcnt")
#define int long long
using namespace std;
const int N=1e6+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
void Write(int ans){
	short x=ans%10;
	if(ans/10)Write(ans/10);
	putchar('0'+x);
}
//int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int gcd(int a,int b){
	if(a>b) a^=b^=a^=b;
	int res=1;
	while(a){
		if(a>b) a^=b^=a^=b;
		if(a&1){
			if(b&1){
				a=b-a;
				b=b-a;
			}
			else{
				b>>=__builtin_ctzll(b);
			}
		}
		else{
			if(b&1){
				a>>=__builtin_ctzll(a);
			}
			else{
				int az=__builtin_ctzll(a);
				int bz=__builtin_ctzll(b);
				a>>=az;
				b>>=bz;
				res<<=min(az,bz);
			}
		}
	}
	return res*b;
}
void exgcd(int a,int b,int &d,__int128 &x,__int128 &y){
	if(!b){d=a;x=1;y=0;}
	else{
		exgcd(b,a%b,d,x,y);
		int t=x;x=y;y=t-a/b*y;
	}
}
__int128 Solve(int y,int b,int n){
	if(!b)return n/gcd(y,n);
	if(b%gcd(y,n)!=0)return -1;
	int d=0;
	__int128 k=0,t=0;
	exgcd(y,n,d,k,t);
	b/=d;y/=d;n/=d;
	return (k*b%(y*n)+(y*n))%((__int128)y*n);
}
int check(int y,int a,int b,int n){
	if(y==0) {
//		Write(Solve(b,0,n));cout<<"!\n";
		a=a*Solve(b,0,n)%n;
//		cout<<a<<endl;
		if(a==0) return -1;
		return gcd(a,n);
	}
	__int128 k1=Solve(b,y,n);
	if(k1==-1) return -1;
	int x0=k1*a%n;
	__int128 k2=Solve(b,0,n);
	a=a*k2%n;
	return x0%gcd(a,n);
}
void work(){
	int a,b,n,ans;
	a=read();b=read();n=read();ans=a*a+b*b;
	for(signed i=0,MAX=sqrt(a*a+b*b);i<=MAX;++i){
		int j=check(i%n,a,b,n);
//		cout<<i<<" "<<j<<endl;
		if(j==-1) continue;
		ans=min(ans,(i%n)*(i%n)+(j%n)*(j%n));
	}
	Write(ans);
	putchar('\n');
}
signed main(){
	int T=read();
	while(T--) work();
	return 0;
}
