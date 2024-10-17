#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=33;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int a[N];
int main(){
    int T=read();
    while(T--){
        ll n=read();
        memset(a,0,sizeof(a));
        for(int i=0;i<=31;i++)a[i]=(n>>i)&1;
        for(int i=0;i<31;i++){
            if((a[i]==1&&a[i+1]==0)||a[i]==2){
                a[i+1]++;
                a[i]-=2;
            }
        }
        bool flag=1;
        for(int i=0;i<31;i++)if(!a[i]&&!a[i+1])flag=0;
        if(!flag){puts("NO");continue;}
        puts("YES");
        for(int i=0;i<=31;i++){
            printf("%d ",a[i]);
            if((i&7)==7)puts("");
        }
    }
    return 0;
}