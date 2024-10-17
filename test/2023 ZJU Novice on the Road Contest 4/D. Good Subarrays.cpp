/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e5+5;
const int M=1e6+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
char a[N];
int n,sum[N],cnt[M];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
    while(T--){
        n=read();
        scanf("%s",a+1);
        ll Ans=0;
        cnt[n]=1;
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+a[i]-'0';
            Ans+=cnt[sum[i]-i+n];
            cnt[sum[i]-i+n]++;
        }
        for(int i=0;i<=n;i++)cnt[sum[i]-i+n]--;
        printf("%lld\n",Ans);
    }
	return 0;
}
