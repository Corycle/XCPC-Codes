/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=105;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,cnt[N];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
    while(T--){
        n=read();
        int Ans=0;
        for(int i=1;i<=n*2;i++)cnt[i]=0;
        for(int i=1;i<=n;i++)cnt[read()]++;
        for(int s=1;s<=n*2;s++){
            int num=0;
            for(int i=1;i<=s/2;i++)num+=min(cnt[i],cnt[s-i]);
            if(!(s&1))num+=cnt[s/2]/2-cnt[s/2];
            Ans=max(Ans,num);
        }
        printf("%d\n",Ans);
    }
	return 0;
}
