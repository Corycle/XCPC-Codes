/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=4e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,a[N],b[N];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int Case=read();
	while(Case--){
		n=read();
		int flag=1;
		for(int i=1;i<=n;i++)a[i]=a[i+n]=read();
		for(int i=1;i<=n;i++)b[i]=b[i+n]=read();
		for(int i=1;i<=n;i++){
			if(a[i]>b[i]){flag=0;break;}
			if(a[i]<b[i]&&b[i]-b[i+1]>=2){flag=0;break;}
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}
