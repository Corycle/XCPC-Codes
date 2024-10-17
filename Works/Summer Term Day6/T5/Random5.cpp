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
int R(){return Rand(100)&1;}
int main(){
	// freopen("T5_10.in","w",stdout);
    srand(time(NULL));
	int n=200000,m=200000;
    printf("%d %d\n",n,m);
    for(int i=1;i<=n;i++)putchar('0'+R());puts("");
    for(int i=1;i<n;i++)printf("%d %d %d %d\n",R(),R(),R(),R());
    for(int i=1;i<=m;i++){
        int op=Rand(3);
        if(op==1){
            int l=Rand(n),r=Rand(n);
            if(l>r)swap(l,r);
            printf("%d %d %d\n",op,l,r);
        }
        if(op==2){
            int x=Rand(n-1);
            printf("%d %d %d %d %d %d\n",op,x,R(),R(),R(),R());
        }
        if(op==3){
            int x=Rand(n);
            printf("%d %d %d\n",op,x,R());
        }
    }
	return 0;
}
