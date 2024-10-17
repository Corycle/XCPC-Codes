/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=3e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,a[N],b[N];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
    int T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++)a[i]=read();
        for(int i=1;i<=n;i++)b[i]=read();
        int flag1=1,flag2=1;
        for(int i=1;i<=n;i++){
            if(a[i]!=b[i])flag1=0;
            if(a[i]!=b[n-i+1])flag2=0;
        }
        if(flag1||flag2)puts("Bob");
        else puts("Alice");
    }
	return 0;
}
