/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}

int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
	for(int t=1;t<=T;t++){
		int a=read(),b=read(),c=read(),d=read();
		int e=read(),f=read(),g=read(),h=read();
		int flag=0;
		if(a==e&&b==f&&c==g&&d==h)flag=1;
		if(a==f&&b==h&&c==e&&d==g)flag=1;
		if(a==g&&b==e&&c==h&&d==f)flag=1;
		if(a==h&&b==g&&c==f&&d==e)flag=1;
		printf("Case #%d: ",t);
		puts(flag?"POSSIBLE":"IMPOSSIBLE");
	}
	return 0;
}
