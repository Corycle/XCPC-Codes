/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int Mod=998244353;
const int N=1e6+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,d;
int mod(int x){return x>=Mod?x-Mod:x;}
struct Tree{
    int c[N];
    int lowbit(int x){return x&(-x);}
    void Add(int x,int d){for(;x<N;x+=lowbit(x))c[x]=mod(c[x]+d);}
    int Sum(int x){int ans=0;for(;x>=1;x-=lowbit(x))ans=mod(ans+c[x]);return ans;}
    int Query(int l,int r){return mod(Sum(r)-Sum(l-1)+Mod);}
}tree;
int main(){
	// freopen("T4_12.in","r",stdin);
	// freopen("T4_12.out","w",stdout);
	n=read();d=read();
    for(int i=1;i<=n;i++){
        int x=read();
        tree.Add(x,mod(tree.Query(max(x-d,1),min(x+d,N-1))+1));
    }
    printf("%d\n",mod(mod(tree.Query(1,N-1)-n)+Mod));
	return 0;
}
