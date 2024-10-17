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
int n,m,a[N],ans[N];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
    while(T--){
        n=read();
        int fst=0;m=0;
        for(int i=1;i<=n;i++)a[i]=read();
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                if(!fst)ans[++m]=0;
                else{
                    int num=i-fst;
                    ans[++m]=num;
                    for(int j=1;j<=num;j++)ans[++m]=0;
                    fst=0;
                }
            }
            else if(!fst)fst=i;
        }
        if(fst)puts("NO");
        else{
            puts("YES");
            for(int i=n;i>=1;i--)printf("%d ",ans[i]);
            puts("");
        }
    }
	return 0;
}
