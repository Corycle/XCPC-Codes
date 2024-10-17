/*====Corycle====*/
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<complex>
#include<cstdio>
#include<vector>
#include<cmath>
#include<ctime>
#include<stack>
#include<queue>
#include<map>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
ll sum;
int n,m,cnt[2],a[N];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
	while(T--){
		n=read();m=read();
		cnt[0]=cnt[1]=sum=0;
		for(int i=1;i<=n;i++){a[i]=read();cnt[a[i]&1]++;sum+=a[i];}
		for(int i=1;i<=m;i++){
			int t=read(),x=read();
			if(x&1){
				sum+=x*cnt[t];
				cnt[t]=0;
				cnt[t^1]=n;
			}
			else sum+=x*cnt[t];
			printf("%lld\n",sum);
		}
	}
	return 0;
}
