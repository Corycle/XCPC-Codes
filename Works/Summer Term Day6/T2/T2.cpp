/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,L[N],R[N];
int main(){
	// freopen("T2_10.in","r",stdin);
	// freopen("T2_10.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n+1;i++)L[i]=i-1;
	for(int i=0;i<=n;i++)R[i]=i+1;
	while(m--){
		char op[3];
		scanf("%s",op);
		int x=read(),y=read();
		if(op[0]=='L'){
			R[L[x]]=R[x];
			L[R[x]]=L[x];
			L[x]=L[y];
			R[x]=y;
			R[L[x]]=L[R[x]]=x;
		}
		else{
			R[L[x]]=R[x];
			L[R[x]]=L[x];
			R[x]=R[y];
			L[x]=y;
			R[L[x]]=L[R[x]]=x;
		}
	}
	for(int x=R[0];x!=n+1;x=R[x])printf("%d ",x);
	return 0;
}
