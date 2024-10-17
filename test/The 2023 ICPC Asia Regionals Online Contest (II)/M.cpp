#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
double a[N];
int main(){
	int T=read();
	while(T--){
		int n=read();
		for(int i=1;i<=n;i++){
			int x=read(),y=read();
			double z;
			cin>>z;
			a[i]=x+y*z;
		}
		sort(a+1,a+n+1);
		double ans=0,sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			ans+=sum;
		}
		printf("%.8lf\n",ans);
	}
	return 0;
}
