/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1005;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,sum[N];
char a[N];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
	while(T--){
		n=read();m=read();
		scanf("%s",a+1);
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+(a[i]=='B');
		}
		if(sum[n]==m){
			puts("0");
			continue;
		}
		puts("1");
		if(sum[n]<m){
			for(int i=1;i<=n;i++){
				if(i+sum[n]-sum[i]==m){
					printf("%d B\n",i);
					break;
				}
			}
			continue;
		}
		if(sum[n]>m){
			for(int i=1;i<=n;i++){
				if(sum[n]-sum[i]==m){
					printf("%d A\n",i);
					break;
				}
			}
		}
	}
	return 0;
}
