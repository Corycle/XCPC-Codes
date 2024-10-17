/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e3+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,a[N];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
    while(T--){
        n=read();
        int sum=0;
        for(int i=1;i<=n;i++){a[i]=read();sum+=a[i];}
        if(sum<=n/2){
            printf("%d\n",n-sum);
            for(int i=1;i<=n-sum;i++)printf("0 ");
            puts("");
        }
        else{
            if(sum&1)sum--;
            printf("%d\n",sum);
            for(int i=1;i<=sum;i++)printf("1 ");
            puts("");
        }
    }
	return 0;
}
