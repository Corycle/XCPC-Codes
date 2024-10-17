/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
__int128 read(){
	__int128 s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
__int128 a,b,c;
__int128 gcd(__int128 a,__int128 b){
	return !b?a:gcd(b,a%b);
}
void Write(__int128 x){
	if(x<10)printf("%d",(int)(x));
	else{Write(x/10);printf("%d",(int)(x%10));}
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	a=read();b=read();c=gcd(a,b);
	Write(c);printf(" ");Write(a/c*b);
	return 0;
}
