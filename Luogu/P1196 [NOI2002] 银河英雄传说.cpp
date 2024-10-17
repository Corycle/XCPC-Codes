/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=3e4+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
char s[5];
int n,m,fa[N],sum[N],num[N];
int Find(int x){
	if(x==fa[x])return x;
	int p=fa[x];
	fa[x]=Find(fa[x]);
	if(p!=fa[x])num[x]+=num[p]+1;
	return fa[x];
}
void Merge(int x,int y){
	x=Find(x);y=Find(y);
	fa[x]=y;num[x]+=sum[y]-1;sum[y]+=sum[x];
}
int Ask(int x){
	Find(x);
//	cout<<x<<" "<<(x==fa[x]?1:num[x]+2)<<endl;
	return x==fa[x]?1:num[x]+2;
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=3e4;m=read();
	for(int i=1;i<=n;i++){fa[i]=i;sum[i]=1;num[i]=0;}
	while(m--){
		scanf("%s",s);
		int x=read(),y=read();
		if(s[0]=='M')Merge(x,y);
		else{
			if(x==y)puts("0");
			else printf("%d\n",Find(x)==Find(y)?abs(Ask(x)-Ask(y))-1:-1);
		}
//		for(int i=1;i<=4;i++)cout<<fa[i]<<" ";cout<<endl;
//		for(int i=1;i<=4;i++)cout<<sum[i]<<" ";cout<<endl;
//		for(int i=1;i<=4;i++)cout<<num[i]<<" ";cout<<endl;
	}
	return 0;
}
