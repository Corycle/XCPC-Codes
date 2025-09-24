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
int n,a[N],b[N],ans[N],fa[N],Max;
int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
void DFS(int x){
	if(x==n+1){
		int cnt=0;
		for(int t=0;t<n;t++){
			for(int i=1;i<=n;i++)fa[i]=i;
			for(int i=1;i<=n;i++)fa[Find(i)]=Find(a[i+t<=n?i+t:i+t-n]);
			for(int i=1;i<=n;i++)if(i==fa[i])cnt++;
		}
//		cout<<cnt<<" :: ";
//		for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//		cout<<endl;
		if(cnt>=Max){
			Max=cnt;
			for(int i=1;i<=n;i++)ans[i]=a[i];
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i])continue;
		b[a[x]=i]=1;
		DFS(x+1);
		b[i]=a[x]=0;
	}
}
void Solve(int id){
	n=id;
	Max=0;
	DFS(1);
	cout<<Max<<" :: ";
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
}
int main(){
	int n=read();
	printf("%lld\n",1ll*(n+1)*n/2);
	for(int i=n;i>=1;i--)printf("%d ",i);
//	for(int i=1;i<=10;i++){
//		Solve(i);
//	}
	return 0;
}
