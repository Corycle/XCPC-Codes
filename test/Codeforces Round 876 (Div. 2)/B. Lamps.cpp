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
int n,m;
struct Node{int a,b;}P[N];
bool cmp(Node A,Node B){return A.a!=B.a?A.a<B.a:A.b>B.b;}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++){
            P[i].a=read();
            P[i].b=read();
        }
        sort(P+1,P+n+1,cmp);
        ll ans=0,num=0,Maxnum=0;
        for(int i=1;i<=n;i++){
            if(P[i].a>Maxnum){
                ans+=P[i].b;
                num++;
            }
            Maxnum=max(Maxnum,num);
            while(num&&P[i-num+1].a<=Maxnum)num--;
        }
        printf("%lld\n",ans);
    }
	return 0;
}
