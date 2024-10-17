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
int Rand(int n){return (rand()*rand()+rand())%n+1;}
int main(){
	srand(time(NULL));
	int n=20,m=5;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++){
		int len=Rand(10);
		while(len--){
			putchar('a'+Rand(5)-1);
		}
		puts("");
	}
	return 0;
}
