/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fst first
#define scd second
#define mp make_pair
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n;
ll Ans;
pii a[N];
priority_queue<int,vector<int>,greater<int> >q;
bool cmp(pii A,pii B){return A>B;}
int main(){
//	freopen("5.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){a[i].fst=read();a[i].scd=read();}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++){
		if(!(i&1)){Ans+=a[i].scd;q.push(a[i].scd);}
		else if(a[i].scd>q.top()){Ans+=a[i].scd-q.top();q.pop();q.push(a[i].scd);}
	}
	printf("%lld\n",Ans);
	return 0;
}
