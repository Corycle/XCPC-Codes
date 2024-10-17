/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=305;
const int M=N*N;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,a[N],b[N],f[M],g[M];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        m+=a[i];
    }
    f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=m/2;j>=a[i];j--){
            if(f[j-a[i]]&&!f[j]){
                f[j]=1;
                g[j]=i;
            }
        }
    }
    if(g[m/2]){
        int t=m/2;
        while(t){
            b[g[t]]=1;
            t-=a[g[t]];
        }
    }
    if(!(m&1)&&g[m/2]){
        puts("Second");
        fflush(stdout);
        while(1){
            int x=read();
            if(!x)break;
            int t=b[x]^1,y=0;
            for(int i=1;i<=n;i++){
                if(a[i]&&b[i]==t){
                    y=i;
                    break;
                }
            }
            printf("%d\n",y);
            fflush(stdout);
            int dlt=min(a[x],a[y]);
            a[x]-=dlt;a[y]-=dlt;
            // for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
        }
    }
    else{
        puts("First");
        fflush(stdout);
        while(1){
            int x=0;
            for(int i=1;i<=n;i++){
                if(a[i]){x=i;break;}
            }
            printf("%d\n",x);
            fflush(stdout);
            int y=read();
            if(!y)break;
            int dlt=min(a[x],a[y]);
            a[x]-=dlt;a[y]-=dlt;
            // for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
        }
    }
	return 0;
}
