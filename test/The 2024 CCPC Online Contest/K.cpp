#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,K;
int main(){
	int T=read();
	while(T--){
		n=read();K=read();
		if(K>=n){puts("Alice");continue;}
		if(n&1){puts("Alice");continue;}
		puts((n&(-n))<=K?"Alice":"Bob");
	}
	return 0;
}
