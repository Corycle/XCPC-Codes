#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,a[N];
signed main(){
    int T=read();
    while(T--){
        n=read();
        int Min=0x3f3f3f3f;
        int flag=1;
        for(int i=1;i<=n;i++){
            a[i]=read();
            if(Min<=a[i]/2)flag=0;
            Min=min(Min,a[i]);
        }
        puts(flag?"YES":"NO");
    }
    return 0;
}