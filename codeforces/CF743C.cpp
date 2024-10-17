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
	int n=read();
    if(n==1){puts("-1");return 0;}
    printf("%d %d %d\n",n,n+1,n*(n+1));
	return 0;
}
