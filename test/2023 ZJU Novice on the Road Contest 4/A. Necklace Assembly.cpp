/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e6+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
char s[N];
int n,m,cnt[N],p[N];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
    while(T--){
        n=read();m=read();
        scanf("%s",s+1);
        for(int i=0;i<26;i++)cnt[i]=0;
        for(int i=1;i<=n;i++)cnt[s[i]-'a']++;
        int Ans=0;
        p[1]=1;
        for(int i=2;i<=m;i++)p[i]=(m%i==0?i:p[i-1]);
        for(int num=1;num<=n;num++){
            int len=0;
            for(int i=0;i<26;i++)len+=cnt[i]/num;
            len=min(len,m);
            Ans=max(Ans,num*p[len]);
        }
        printf("%d\n",Ans);
    }
	return 0;
}
