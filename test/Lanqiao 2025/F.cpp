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
char s[N];
int n,a[N],sum[N],cnt[N];
ll ans;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		a[i]=!((s[i]==s[i-1])|(s[i]==s[i-1]+1));
		sum[i]=sum[i-1]+a[i];
		cnt[sum[i]]++;
		ans+=cnt[sum[i]]+cnt[sum[i]-1];
	}
	printf("%lld\n",ans);
	return 0;
}
