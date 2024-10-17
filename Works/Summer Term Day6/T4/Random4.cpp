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
	// freopen("T4_11.in","w",stdout);
    srand(time(NULL));
    // puts("2 5");
    // puts("2 23");
    // return 0;
	int n=100000,d=451145;
    printf("%d %d\n",n,d);
    for(int i=1;i<=n;i++)printf("%d ",Rand(1000000));
	return 0;
}
