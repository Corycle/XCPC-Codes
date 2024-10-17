#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int st[N],top,n,a[N],L[N],R[N];
int main(){
    int T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++)a[i]=read();
        a[0]=a[n+1]=0x3f3f3f3f;
        st[top=0]=0;
        for(int i=1;i<=n;i++){
            while(top&&a[i]>a[st[top]])top--;
            L[i]=st[top];
            if(a[st[top]]==a[i])L[i]=i-1;
            st[++top]=i;
        }
        st[top=0]=n+1;
        for(int i=n;i>=1;i--){
            while(top&&a[i]>a[st[top]])top--;
            R[i]=st[top];
            st[++top]=i;
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            // cout<<L[i]<<" "<<R[i]<<endl;
            ans+=(R[i]-L[i]-2);
        }
        printf("%lld\n",ans);
    }
    return 0;
}