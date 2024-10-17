/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,q;
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
    while(T--){
        n=read();m=read();q=read();
        int len=0;
        ll ans=0;
        for(int i=1;i<=n;i++){
            int x=read();
            if(x<=q)len++;
            else{
                if(len>=m){
                    ans+=1ll*(len-m+2)*(len-m+1)/2;
                }
                len=0;
            }
        }
        if(len>=m){
            ans+=1ll*(len-m+2)*(len-m+1)/2;
        }
        printf("%lld\n",ans);
    }
	return 0;
}
