#include<bits/stdc++.h>
using namespace std;
const int N=105;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
struct Ques{int l,r;}P[N];
int n,m,a[N];
int main(){
    int T=read();
    while(T--){
        n=read();m=0;
        for(int i=1;i<=n;i++)a[i]=read();
        for(int i=1;i<=n;i++){
            int r=i;
            for(int j=i+1;j<=n;j++)if(a[j]<a[i])r=j;
            if(r==i)continue;
            sort(a+i,a+r+1);
            P[++m]=(Ques){i,r};
        }
        printf("%d\n",m);
        for(int i=1;i<=m;i++)printf("%d %d\n",P[i].l,P[i].r);
    }

    return 0;
}