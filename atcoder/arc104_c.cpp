/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=205;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,a[N],b[N],p[N],f[N],id[N],num[N];
bool Check(int l,int r){
    if((r-l+1)&1)return false;
    for(int i=l;i<=r;i++){
        if(id[i]&& p[i]&&b[id[i]]!=-1&&b[id[i]]>r)return false;
        if(id[i]&&!p[i]&&a[id[i]]!=-1&&a[id[i]]<l)return false;
    }
    int t=(r-l+1)>>1,mid=(l+r)>>1;
    for(int i=l;i<=mid;i++)if(id[i]&&!p[i])return false;
    for(int i=l+t;i<=r;i++)if(id[i]&& p[i])return false;
    for(int i=l;i<=mid;i++)if(id[i]&&id[i+t]&&id[i]!=id[i+t])return false;
    return true;
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();b[i]=read();
        if(a[i]!=-1&&b[i]!=-1&&a[i]>=b[i]){puts("No");return 0;}
        if(a[i]!=-1){num[a[i]]++;id[a[i]]=i;p[a[i]]=1;}
        if(b[i]!=-1){num[b[i]]++;id[b[i]]=i;p[b[i]]=0;}
    }
    for(int i=1;i<=n*2;i++)if(num[i]>=2){puts("No");return 0;}
    f[0]=1;
    for(int i=1;i<=n*2;i++){
        if(!num[i]&&f[i-1])f[i]=1;
        for(int j=1;j<=i;j++)f[i]|=f[j-1]&Check(j,i);
    }
    puts(f[n*2]?"Yes":"No");
	return 0;
}
