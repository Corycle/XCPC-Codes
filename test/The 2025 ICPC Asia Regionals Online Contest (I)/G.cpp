#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m;
bool vis[N];
int main(){
	n=read();m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		if(y==x+1)vis[x]=1;
	}
	for(int i=1;i<n;i++)if(!vis[i]){puts("No");return 0;}
	puts("Yes");
	return 0;
}
