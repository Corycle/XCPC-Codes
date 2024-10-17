#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
ll Ans;
int n,m;
int fa[N];
ll num[N],sum[N],a[N];
int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++){fa[i]=i;num[i]=1;sum[i]=0;}
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		x=Find(x);y=Find(y);
		if(x==y){
			sum[x]++;
		}
		else{
			fa[y]=x;
			sum[x]+=sum[y]+1;
			num[x]+=num[y];
		}
	}
	int flag=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(i==fa[i]){
			a[++cnt]=num[i];
			if(sum[i]!=num[i]*(num[i]-1)/2){
				flag=1;
				Ans+=num[i]*(num[i]-1)/2-sum[i];
			}
		}
	}
	if(flag){
		printf("%lld\n",Ans);
		return 0;
	}
	sort(a+1,a+cnt+1);
	Ans=a[1]*a[2];
	printf("%lld\n",Ans);
    return 0;
}
