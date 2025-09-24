#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fst first
#define scd second
#define mp make_pair
using namespace std;
const int N=1e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,a[N],b[N],c[N],num[N],id[N],qnum[N];
ll ans[N];
struct Ques{
	int val,id;
};
vector<Ques> Q1[N],Q2[N];
pii Q[N];
map<pii,int> used,ID;
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=b[i]=read();
	}
	sort(b+1,b+n+1);
	b[0]=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(b+1,b+b[0]+1,a[i])-b;
		num[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		int v1=lower_bound(b+1,b+b[0]+1,x)-b;
		int v2=lower_bound(b+1,b+b[0]+1,y)-b;
		if(x!=b[v1]||y!=b[v2])continue;
		Q[i]=mp(v1,v2);
		if(used[Q[i]]){
			id[i]=ID[Q[i]];
		}
		else {
			id[i]=ID[Q[i]]=i;
			used[Q[i]]=1;
		}
		qnum[v1]++;
		qnum[v2]++;
	}
	for(int i=1;i<=m;i++){
		int v1=Q[i].fst,v2=Q[i].scd;
		if(id[i]!=i)continue;
		if(v1==v2){
			ans[i]=1ll*(num[v1]-1)*num[v1]/2;
			continue;
		}
		if(qnum[v1]<qnum[v2])Q1[v1].push_back((Ques){v2,i});
		else Q2[v2].push_back((Ques){v1,i});
	}
	for(int i=1;i<=n;i++)num[i]=0;
	for(int i=1;i<=n;i++){
		for(auto ques:Q2[a[i]]){
			ans[ques.id]+=num[ques.val];
		}
		num[a[i]]++;
	}
	for(int i=1;i<=n;i++)num[i]=0;
	for(int i=n;i>=1;i--){
		for(auto ques:Q1[a[i]]){
			ans[ques.id]+=num[ques.val];
		}
		num[a[i]]++;
	}
	for(int i=1;i<=m;i++){
//		cout<<id[i]<<" : ";
		printf("%lld\n",ans[id[i]]);
	}
	return 0;
}
