/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const double eps=1e-5;
const int N=1e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m;
struct Point{ll x,y;}P[N],S,T;
ll Dis(Point A,Point B){
    return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
    int Case=read();
    while(Case--){
        n=read();
        for(int i=1;i<=n;i++){P[i].x=read();P[i].y=read();}
        S.x=read();S.y=read();T.x=read();T.y=read();
        bool flag=true;
        for(int i=1;i<=n;i++){
            if(Dis(P[i],T)<=Dis(S,T))flag=false;
        }
        puts(flag?"Yes":"No");
    }
	return 0;
}
