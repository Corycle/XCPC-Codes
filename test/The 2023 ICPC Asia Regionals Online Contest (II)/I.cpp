#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5; 
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,a[N];
long double q[N];
void work(){
	n=read();
	for(int i=0;i<n;++i) a[i]=read();
	for(int i=0;i<n;++i) q[i]=1-read()/100000.0;
	long double ans=n;
	for(int i=0;i<n;i++){
		long double ti = (1+q[i]*(i-a[i]))/(1-q[i]);
		ans=min(ans,i+ti);
	}
	
	
	cout<<fixed<<setprecision(12)<<ans<<"\n";
}
int main(){
	int T=read();
	while(T--) work();
}
