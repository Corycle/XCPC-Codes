/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int Mod=998244353;
const int N=2.5e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,Ans,num,pos,a[N],b[N];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();m=read();Ans=1;
	for(int i=1;i<=m;i++)b[a[i]=read()]=i;
	for(int i=2;i<=m;i++)if(a[i]<a[i-1]){pos=i;break;}
	if(!pos)pos=n+1;
	for(int i=1;i<=n;i++){
		if(b[i])num+=(a[b[i]-1]<=i&&b[i]-1<pos)+(a[b[i]+1]<=i&&b[i]<pos);
		else{
			Ans=1ll*Ans*num%Mod;
			num++;
		}
	}
	printf("%d\n",Ans);
	return 0;
}
