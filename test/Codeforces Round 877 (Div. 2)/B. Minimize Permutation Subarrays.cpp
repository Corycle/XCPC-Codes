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
        int pos1=0,pos2=0,posn=0;
        for(int i=1;i<=n;i++){
            a[i]=read();
            if(a[i]==1)pos1=i;
            if(a[i]==2)pos2=i;
            if(a[i]==n)posn=i;
        }
        if(pos1>pos2)swap(pos1,pos2);
        if(pos2==pos1+1){
            if(posn<pos1)printf("%d %d\n",pos1,posn);
            else printf("%d %d\n",pos2,posn);
        }
        else printf("%d %d\n",pos1+1,posn);
    }

	return 0;
}
