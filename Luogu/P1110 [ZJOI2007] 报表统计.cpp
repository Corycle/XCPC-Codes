/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
#define set_it multiset<int>::iterator
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e6+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
multiset<int>F;
char s[15];
int n,m,Ans;
int a[N],b[N],L[N],R[N],lst[N];
struct Heap{
	priority_queue<int,vector<int>,greater<int> >q1,q2;
	void Insert(int x){q1.push(x);}
	void Delete(int x){q2.push(x);}
	int Top(){
		while(!q1.empty()&&!q2.empty()&&q1.top()==q2.top()){q1.pop();q2.pop();}
		return q1.top();
	}
}H;
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();m=read();Ans=inf;
	for(int i=1;i<=n;i++){a[i]=b[i]=read();F.insert(a[i]);L[i]=i-1;R[i]=i+1;lst[i]=i;}
	R[n]=0;
	sort(b+1,b+n+1);
	for(int i=1;i<n;i++){Ans=min(Ans,b[i+1]-b[i]);H.Insert(abs(a[i+1]-a[i]));}
	F.insert(-inf);F.insert(inf);
	while(m--){
		scanf("%s",s);int len=strlen(s);
		if(len==6){
			int pos=read();a[++n]=read();
			L[n]=lst[pos];R[n]=R[lst[pos]];R[L[n]]=n;L[R[n]]=n;lst[pos]=n;
			if(L[n]&&R[n])H.Delete(abs(a[R[n]]-a[L[n]]));
			if(L[n])H.Insert(abs(a[n]-a[L[n]]));
			if(R[n])H.Insert(abs(a[n]-a[R[n]]));
			F.insert(a[n]);
			set_it p=F.find(a[n]),l=--p,r=++++p;
			Ans=min(Ans,min(a[n]-(*l),(*r)-a[n]));
		}
		else if(len==7)printf("%d\n",H.Top());
		else if(len==12)printf("%d\n",Ans);
	}
	return 0;
}
