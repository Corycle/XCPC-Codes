/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=4e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,b[N];
pii a[N];
struct BIT{
    int c[N],n;
    int lowbit(int x){return x&(-x);}
    void Init(int m){n=m;for(int i=1;i<=n;i++)c[i]=n;}
    void Update(int x,int y){for(;x<=n;x+=lowbit(x))c[x]=min(c[x],y);}
    int Ask(int x){int ans=inf;for(;x>=1;x-=lowbit(x))ans=min(ans,c[x]);return ans;}
}tree;
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
    while(T--){
        n=read();b[0]=0;
        for(int i=1;i<=n;i++)b[++b[0]]=a[i].first=read();
        for(int i=1;i<=n;i++)b[++b[0]]=a[i].second=read();
        sort(a+1,a+n+1);
        sort(b+1,b+b[0]+1);
        b[0]=unique(b+1,b+b[0]+1)-b-1;
        tree.Init(b[0]+1);
        for(int i=1;i<=n;i++){
            a[i].first=lower_bound(b+1,b+b[0]+1,a[i].first)-b;
            a[i].second=lower_bound(b+1,b+b[0]+1,a[i].second)-b;
        }
        ll sum=0;
        int ans=0,Min=b[0]+1;b[b[0]+1]=inf;
        for(int i=1;i<=n;i++){
            sum+=abs(b[a[i].first]-b[a[i].second]);
            if(a[i].second>=a[i].first){
                ans=max(ans,2*(b[a[i].first]-b[Min]));
                ans=max(ans,2*(b[a[i].first]-b[tree.Ask(a[i].first)]));
            }
            else{
                ans=max(ans,2*(b[a[i].second]-b[Min]));
                ans=max(ans,2*(b[a[i].second]-b[tree.Ask(a[i].second)]));
            }

            if(a[i].second<=a[i].first)Min=min(Min,a[i].first);
            if(a[i].first<=a[i].second)tree.Update(a[i].second,a[i].second);
        }
        printf("%lld\n",ans+sum);
    }
	return 0;
}
