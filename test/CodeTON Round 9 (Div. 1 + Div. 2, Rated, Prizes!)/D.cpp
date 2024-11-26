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
int n,m,cnt,a[N],b[N],f[N];
vector<int>G[N];
void Prepare(){
    for(int i=2;i<N;i++){
        for(int j=i*2;j<N;j+=i){
            G[j].push_back(i);
        }
    }
    for(int i=2;i<N;i++){
        b[0]=0;
        for(auto x:G[i]){
            b[++b[0]]=f[x];
        }
        sort(b+1,b+b[0]+1);
        f[i]=unique(b+1,b+b[0]+1)-b;
    }
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
    Prepare();
    int T=read();
    while(T--){
        n=read();m=read();
        for(int i=1;i<=m;i++){
            a[i]=read();
        }
        sort(a+1,a+m+1);
        int flag=1;
        for(int i=1;i<=n;i++){
            if(m-f[i]<=0)flag=0;
        }
        if(!flag){
            puts("-1");
            continue;
        }
        for(int i=1;i<=n;i++){
            printf("%d ",a[m-f[i]]);
        }
        puts("");
    }
	return 0;
}
