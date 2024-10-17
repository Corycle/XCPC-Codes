/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=9e18;
const int inf=0x3f3f3f3f;
const int N=5005;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
ll Ans;
int n,m,a[N],b[N],c[N],d[N];
char S[N],T[N],s[N],t[N];
bool cmp(int x,int y){return c[x]>c[y];}
ll Solve(int num){
	ll ans=0,sum=0;a[0]=b[0]=0;
	for(int i=1;i<=n;i++){s[i]=S[i];t[i]=T[i];sum+=(s[i]-'0')*c[i];}
	for(int i=1;i<=num;i++)if(s[d[i]]=='1'){sum-=c[d[i]];ans+=sum;s[d[i]]='0';}
	for(int i=1;i<=n;i++){
		if(s[i]!=t[i]&&s[i]=='1')a[++a[0]]=i;
		if(s[i]!=t[i]&&s[i]=='0')b[++b[0]]=i;
	}
	sort(a+1,a+a[0]+1,cmp);
	sort(b+1,b+b[0]+1,cmp);
	for(int i=1;i<=a[0];i++){sum-=c[a[i]];ans+=sum;}
	for(int i=b[0];i>=1;i--){sum+=c[b[i]];ans+=sum;}
	return ans;
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){c[i]=read();d[i]=i;}
	scanf("%s%s",S+1,T+1);
	sort(d+1,d+n+1,cmp);
	Ans=Solve(0);
	for(int i=1;i<=n;i++)if(S[d[i]]=='1')Ans=min(Ans,Solve(i));
	printf("%lld\n",Ans);
	return 0;
}
