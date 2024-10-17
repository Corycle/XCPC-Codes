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
int n,m;
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int Case=read();
	while(Case--){
		n=read();m=read();
		if(n>m){puts("No");continue;}
		if(n&1){
			puts("Yes");
			for(int i=1;i<n;i++)printf("1 ");
			printf("%d\n",m-n+1);
		}
		else{
			if(m&1){puts("No");continue;}
			puts("Yes");
			for(int i=1;i<=n-2;i++)printf("1 ");
			printf("%d %d\n",(m-(n-2))/2,(m-(n-2))/2);
		}
	}
	return 0;
}
