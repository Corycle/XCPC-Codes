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
int F(int l,int r){return (a[r]-a[l]+1)/2;}
int Get(int L){
    int pos=L;
    int l=L,r=n;
    while(r-l>=10){
        int mid1=(l+l+r)/3;
        int mid2=(l+r+r)/3;
        if(max(F(L,mid1),F(mid1+1,n))<max(F(L,mid2),F(mid2+1,n))){
            r=mid2;
        }
        else l=mid1;
    }
    int res=inf;
    for(int i=l;i<=r;i++)res=min(res,max(F(L,i),F(i+1,n)));
    return res;
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++)a[i]=read();
        sort(a+1,a+n+1);
        n=unique(a+1,a+n+1)-a-1;
        if(n<=3){puts("0");continue;}
        int ans=inf;
        for(int l=1;l<=n-2;l++){
            int t=Get(l+1);
            ans=min(ans,max(F(1,l),t));
        }
        printf("%d\n",ans);
    }
	return 0;
}
