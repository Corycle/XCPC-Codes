/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,a[N];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++){
            a[i]=read();
        }
        ll lst=a[n],ans=0;
        for(int i=n-1;i>=1;i--){
            if(a[i]<=lst){
                lst=a[i];
            }
            else{
                if(a[i]%lst==0){
                    ans+=a[i]/lst-1;
                }
                else{
                    ans+=a[i]/lst;
                    lst=max(a[i]%lst,a[i]/(a[i]/lst+1));
                }
            }
        }
        printf("%lld\n",ans);
    }
	return 0;
}
