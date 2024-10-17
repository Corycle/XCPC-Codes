#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int M=6;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,K;
void work(){
	n=read();m=read();K=read();
	if(n==1&&m==1){
		if(K==1){
			puts("Yes")
			puts("*");
			return;
		}
		if(K>1){
			puts("No");
			return;
		}
	}
	if(n==1){
		if(K==1){
			puts("Yes")
			for(int i=1;i<=m;++i) printf("*"); puts("");
			return;
		}
		if(K==2){
			puts("Yes");
			for(int i=1;i<m;++i) printf("."); puts("*");
			return;
		}
		if(K==3){
			if(m==2){
				puts("No");
				return;
			}
			puts("Yes");
			printf("."); for(int i=2;i<m;++i) printf("*"); puts(".");
		}
			puts("No");
			return;
		return ;
	}
	if(m==1){
		return ;
	}
	if(K==1){
		puts("Yes");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				
			}
		}
		continue;
	}
}
int main(){
	int T=read();
	while(T--){
		work();
	}
	return 0;
}
