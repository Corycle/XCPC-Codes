#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+5;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,a[N],b[N],c[N],nxt[N],vis[N];
ll Ans,sum[N];
int main(){
    n=read();
    int lst=1;
    for(int i=1,j=0;i<=n;i++){
        c[i]=(read()+Ans)%n;
        // c[i]=read();
        a[i]=read();b[i]=read();
        // cout<<"Input: "<<c[i]<<" "<<a[i]<<" "<<b[i]<<endl;
        if(i==1){
            nxt[i]=0;
            vis[i]=1;
        }
        else{
            while(j>0&&c[i]!=c[j+1])j=nxt[j];
            if(c[i]==c[j+1])j++;
            nxt[i]=j;
        }
        vis[i]=vis[nxt[i]];
        if(vis[i]){
            if(i==1)sum[i]=b[1];
            else if(nxt[i]==1){
                sum[i]=b[1]+b[i];
            }
            else{
                sum[i]=sum[i-nxt[i]+1]+b[i];
            }
            lst=i;
        }
        else if(nxt[i]==nxt[i-1]+1)sum[i]=sum[i-1];
        else {
            sum[i]=(nxt[i]==0?b[1]:sum[nxt[i]]+b[lst]);
        }
        // cout<<"Next: "<<nxt[i]<<endl;
        // cout<<"Sum:  "<<sum[i]<<endl;
        Ans+=sum[i]*a[i];
        printf("%lld\n",Ans);
    }
    return 0;
}