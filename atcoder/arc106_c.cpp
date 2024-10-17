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
int n,m,p;
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();m=read();
    if(m<0||(m&&n<m+2)){puts("-1");return 0;}
    if(m){
        printf("%d %d\n",1,(m+2)*2);
        for(int i=1;i<=m+1;i++)printf("%d %d\n",2*i,2*i+1);
        n-=m+2;
        p=(m+2)*2;
    }
    for(int i=1;i<=n;i++){
        printf("%d %d\n",p+1,p+2);
        p+=2;
    }
	return 0;
}
