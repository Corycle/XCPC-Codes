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
int Rand(int x){return (1ll*rand()*rand()+rand())%x+1;}
int main(){
	// freopen("T2_10.in","w",stdout);
    srand(time(NULL));
	int n=100000,m=100000;
    printf("%d %d\n",n,m);
    for(int i=1;i<=m;i++){
        int x=Rand(n),y=Rand(n);
        while(x==y)y=Rand(n);
        putchar(Rand(100)&1?'L':'R');
        printf(" %d %d\n",x,y);
    }
	return 0;
}
