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
struct Node{
	int l,r;
}a[N];
bool cmp(Node A,Node B){
	return A.l!=B.l?A.l<B.l:A.r<B.r;
}
int GetAns(){
	int ans=n;
	sort(a+1,a+m+1,cmp);
	
	return ans;
}
int main(){
	int T=read();
	while(T--){
		m=read();n=read();
		for(int i=1;i<=m;i++){
			a[i].l=read();
			a[i].r=read();
		}
		int ans=GetAns();
		printf("%d\n",ans);
	}
	return 0;
}
