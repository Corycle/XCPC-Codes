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
struct BIT{
	int c[N];
	int lowbit(int x){return x&(-x);}
	void Add(int x,int y){for(;x<N;x+=lowbit(x))c[x]+=y;}
	int Ask(int x){int ans=0;for(;x>=1;x-=lowbit(x))ans+=c[x];}
	int Query(int l,int r){return Ask(r)-Ask(l-1);}
}tree;
int cnt,prime[N],vis[N];
void Prepare(){
	for(int i=2;i<N;i++){
		if(!vis[i])prime[++cnt]=i;
		for(int j=1;j<=cnt&&1ll*i*prime[j]<N;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}
int fa[N];
int Find(int x){return x==fa[x]?x:fa[x]=Find(x);}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}

int main(){
	
	return 0;
}
