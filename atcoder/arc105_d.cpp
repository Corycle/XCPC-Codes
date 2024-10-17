/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e5+5;
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
	int Case=read();
    while(Case--){
        n=read();
        for(int i=1;i<=n;i++)a[i]=read();
        if(n&1){puts("Second");continue;}
        sort(a+1,a+n+1);
        int flag=1;
        for(int i=1;i<=n;i+=2)flag&=(a[i]==a[i+1]);
        puts(flag?"Second":"First");
    }
	return 0;
}
