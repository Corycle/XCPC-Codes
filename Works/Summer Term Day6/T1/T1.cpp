/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e6+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
char a[N];
int n,top,st[N],ans[N];
int main(){
	// freopen("T1_10.in","r",stdin);
	// freopen("T1_10.out","w",stdout);
	n=read();
	scanf("%s",a+1);
	for(int i=1;i<=n;i++){
		if(a[i]=='(')st[++top]=i;
		else ans[st[top--]]=i;
	}
	for(int i=1;i<=n;i++){
		if(a[i]=='(')printf("%d ",ans[i]);
	}
	return 0;
}
