/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=5e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,num;
ll Sum,a1[N],a2[N];
int a[N],st[N],ed[N],pos[N],Num[N];
struct Node{int l,r,id;}P[N];
bool cmp(Node A,Node B){return pos[A.l]!=pos[B.l]?pos[A.l]<pos[B.l]:pos[A.r]<pos[B.r];}
void Prepare(){
	int blk=max((int)sqrt(n),233);
	while(ed[num]!=n){num++;st[num]=ed[num-1]+1;ed[num]=min(ed[num-1]+blk,n);}
	for(int i=1;i<=num;i++)for(int j=st[i];j<=ed[i];j++)pos[j]=i;
}
ll Cn2(ll x){return x*(x-1)/2;}
ll gcd(ll x,ll y){return !y?x:gcd(y,x%y);}
void Add(int x){Sum-=Cn2(Num[a[x]]);Num[a[x]]++;Sum+=Cn2(Num[a[x]]);}
void Del(int x){Sum-=Cn2(Num[a[x]]);Num[a[x]]--;Sum+=Cn2(Num[a[x]]);}
void Solve(){
	int L=1,R=0;
	for(int i=1;i<=m;i++){
		int l=P[i].l,r=P[i].r;
		if(l==r){a1[P[i].id]=0;a2[P[i].id]=1;continue;}
		while(R<r)Add(++R);while(R>r)Del(R--);
		while(L<l)Del(L++);while(L>l)Add(--L);
		if(!Sum){a1[P[i].id]=0;a2[P[i].id]=1;}
		else{
			ll D=Cn2(r-l+1),g=gcd(Sum,D);
			a1[P[i].id]=Sum/g;a2[P[i].id]=D/g;
		}
	}
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();m=read();Prepare();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++){P[i].l=read();P[i].r=read();P[i].id=i;}
	sort(P+1,P+m+1,cmp);
	Solve();
	for(int i=1;i<=m;i++)printf("%lld/%lld\n",a1[i],a2[i]);
	return 0;
}
