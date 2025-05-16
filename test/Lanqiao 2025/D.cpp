#include<bits/stdc++.h>
using namespace std;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int main(){
	int T=read();
	while(T--){
		int x=read(),y=read();
		int id=(1<<(x-1))-1+y;
		int sum=0;
		while(id!=1){
			sum+=(id&1);
			id>>=1;
		}
		puts(sum&1?"BLACK":"RED");
	}
	return 0;
}
