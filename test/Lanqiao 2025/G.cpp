#include<bits/stdc++.h>
#define ll long long
using namespace std;
const double pi=acos(-1);
const double eps=1e-8;
const int N=1e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n;
double ans;
struct Node{
	double l,r;
}a[N];
double L(double x,double y){
	return sqrt(x*x+y*y);
}
bool cmp(Node A,Node B){
	return (abs(A.l-B.l)>eps)?A.l<B.l:A.r<B.r;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		double x=read(),y=read(),r=read();
		double z=L(x,y);
		a[i].l=acos(x/z)-acos(sqrt(z*z-r*r)/z);
		a[i].r=acos(x/z)+acos(sqrt(z*z-r*r)/z);
	}
	sort(a+1,a+n+1,cmp);
	double arg=0;
	for(int i=1;i<=n;i++){
		ans+=max(a[i].l-arg,0.0);
		arg=max(arg,a[i].r);
	}
	ans+=(pi/2)-arg;
	printf("%.3lf\n",ans/(pi/2));
	return 0;
}
