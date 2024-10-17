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
	// freopen("T1_10.in","w",stdout);
    srand(time(NULL));
	int n=1000000,s=0;
    printf("%d\n",n);
    for(int i=1;i<=n;i++){
        if(!s||(Rand(100)<=60&&n-i>=s+1)){
            s++;
            putchar('(');
        }
        else{
            s--;
            putchar(')');
        }
    }
	return 0;
}
