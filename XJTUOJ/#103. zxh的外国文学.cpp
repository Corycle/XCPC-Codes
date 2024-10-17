/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
ll read(){
	ll s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}

int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	ll x=read(),y=read();
	printf("%lld %lld ",x,y);
	if(y==2){
		if(x%4)puts("28");
		else if(!(x%100)&&x%400)puts("28");
		else puts("29");
	}
	else if(y==1||y==3||y==5||y==7||y==8||y==10||y==12)puts("31");
	else puts("30");
	return 0;
}
