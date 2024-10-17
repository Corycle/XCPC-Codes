#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const double eps=1e-8;
ll read(){
	ll s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
ll n,K,T,sum1[N],sum2[N];
struct Node{ll a,id;}P[N];
bool cmp1(Node A,Node B){return A.a<B.a;}
bool cmp2(Node A,Node B){return A.id<B.id;}
bool Check(int i){
	double S1=sum1[i+K-1]-sum1[i-1];
	double S2=sum2[i+K-1]-sum2[i-1];
	return S2/K-(S1/K)*(S1/K)<T-eps;
}
bool Solve(int t){
	sort(P+1,P+n+1,cmp2);
	sort(P+1,P+t+1,cmp1);
	for(int i=1;i<=t;i++){
		sum1[i]=sum1[i-1]+P[i].a;
		sum2[i]=sum2[i-1]+P[i].a*P[i].a;
	}
	for(int i=1;i+K-1<=t;i++){
		if(Check(i))return true;
	}
	return false;
}
int main(){
	n=read();K=read();T=read();
	for(int i=1;i<=n;i++){P[i].a=read();P[i].id=i;}
	int l=K,r=n,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(Solve(mid)){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}
