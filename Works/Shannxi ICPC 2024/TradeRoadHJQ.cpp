/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,a[N],cnt[N];
int Dist(int x,int y){
	return min((a[y]-a[x]+m)%m,(a[x]-a[y]+m)%m);
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	m=read();n=read();
	for(int i=1;i<=n;i++)a[i]=a[i+n]=read();
	if(n==2){
		puts("1");
		return 0;
	}
	if(n==3){
		if(a[2]-a[1]==a[3]-a[2]&&a[2]-a[1]==a[1]-a[3]+m)puts("3");
		else puts("2");
		return 0;
	}
	for(int i=1,j=2;i<=n;i++){
		while(j<=i+n-1&&Dist(i,j+1)>Dist(i,j))j++;
		cnt[j]++;
		if(Dist(i,j)==Dist(i,j+1))cnt[j+1]++;
		// for(int k=1;k<=n;k++)cout<<cnt[k]+cnt[k+n]<<" ";
		// cout<<endl;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		cnt[i]+=cnt[i+n];
		ans=max(ans,cnt[i]);
	}
	printf("%d\n",ans);
	return 0;
}
