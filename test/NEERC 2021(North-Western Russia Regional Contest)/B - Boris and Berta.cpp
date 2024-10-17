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
int n,m,c,ans,x,y;
int main(){
	n=read();m=read();c=read();
	ans=inf;
	for(int i=0;i<=n+m;i+=m){
		if(abs(i+max(n-i,0)/c*c-n)<ans){
			x=i/m;y=max(n-i,0)/c;
			ans=abs(i+max(n-i,0)/c*c-n);
		}
		if(abs(i+max(n-i,0)/c*c+c-n)<ans){
			x=i/m;y=max(n-i,0)/c+1;
			ans=abs(i+max(n-i,0)/c*c+c-n);
		}
	}
	printf("%d %d\n",x,y);
	return 0;
}
