/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=0x3f3f3f3f;
const ll N=2e5+5;
ll read(){
	ll s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
ll n,m,cnt,a[N],h[N],vis[N];
struct edge{ll to,next,v;}d[N];
void Add(ll x,ll y,ll z){d[++cnt]=(edge){y,h[x],z};h[x]=cnt;}
void DFS(ll x,ll xors){
	a[x]=xors;vis[x]=1;
	for(ll i=h[x];i;i=d[i].next){
		ll y=d[i].to;
		if(vis[y])continue;
		DFS(y,xors^d[i].v);
	}
}
struct Basis{
	ll a[60];
	void Init(){memset(a,0,sizeof(a));}
	void Insert(ll x){
		for(ll i=60;i>=0;i--){
			if(!((x>>i)&1))continue;
			if(a[i])x^=a[i];
			else{a[i]=x;return;}
		}
	}
	ll Query(){
		ll ans=0;
		for(ll i=60;i>=0;i--)ans=max(ans,ans^a[i]);
		return ans;
	}
}F;
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	ll T=read();
	for(ll Case=1;Case<=T;Case++){
		n=read();m=read();cnt=0;
		for(ll i=1;i<=n;i++)h[i]=vis[i]=0;
		for(ll i=1;i<=m;i++){ll x=read(),y=read(),z=read();Add(x,y,z);Add(y,x,z);}
		DFS(1,0);
		F.Init();
		for(ll x=1;x<=n;x++){
			for(ll i=h[x];i;i=d[i].next){
				ll y=d[i].to;
				F.Insert(a[x]^a[y]^d[i].v);
			}
		}
		printf("Case #%lld: %lld\n",Case,F.Query());
	}
	return 0;
}
