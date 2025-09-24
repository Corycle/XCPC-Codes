#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fst first
#define scd second
#define mp make_pair
using namespace std;
const int N=2e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
struct Node{
	int val,x,id;
	friend bool operator<(Node A,Node B){
		return A.val>B.val;
	}
};
set<pii> S;
priority_queue<Node> Q;
int n,m,a[N],vis[N];
void Update(int x){
	auto p=S.lower_bound(mp(x,0));
	if(p==S.end())return;
	Q.push((Node){p->fst-x,p->fst,p->scd});
}
void Insert(pii p){
	int x=p.fst;
	if(S.find(p)!=S.end())S.erase(p);
	Update(-x);
	Update(m-x);
	Update(m*2-x);
}
int main(){
	int T=read();
	while(T--){
		while(Q.size())Q.pop();
		S.clear();
		n=read();m=read();
		for(int i=1;i<=n;i++){
			a[i]=read()%m;
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			S.insert(mp(a[i],i));
			vis[i]=0;
		}
		Insert(mp(a[1],1));
		vis[1]=1;
		ll ans=0;
		while(Q.size()){
			auto p=Q.top();Q.pop();
			if(vis[p.id])continue;
			vis[p.id]=1;
			ans+=p.val;
			Insert(mp(p.x,p.id));
			Update(p.x-p.val-m);
			Update(p.x-p.val);
			Update(p.x-p.val+m);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
