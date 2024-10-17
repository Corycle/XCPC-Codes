/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e4+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int sum[N];
int Day(int x,int y){
	if(y==2){
		if(x%4)return 28;
		if(!(x%100)&&x%400)return 28;
		return 29;
	}
	if(y==1||y==3||y==5||y==7||y==8||y==10||y==12)return 31;
	return 30;
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	for(int i=1;i<=9999;i++)sum[i]=sum[i-1]+(Day(i-1,2)==28?365:366);// before year i
	int T=read();
	while(T--){
		int Y1=read(),M1=read(),D1=read(),h1=read(),m1=read(),s1=read();
		int Y2=read(),M2=read(),D2=read(),h2=read(),m2=read(),s2=read();
		if(Y1==0||Y2==0||M1>12||M2>12||D1>Day(Y1,M1)||D2>Day(Y2,M2)||h1>=24||h2>=24||m1>=60||m2>=60||s1>=60||s2>=60){puts("-1");continue;}
		if((Y1>Y2)||(Y1==Y2&&M1>M2)||(Y1==Y2&&M1==M2&&D1>D2)||(Y1==Y2&&M1==M2&&D1==D2&&h1>h2)||(Y1==Y2&&M1==M2&&D1==D2&&h1==h2&&m1>m2)||(Y1==Y2&&M1==M2&&D1==D2&&h1==h2&&m1==m2&&s1>s2)){
			swap(Y1,Y2);swap(M1,M2);swap(D1,D2);swap(h1,h2);swap(m1,m2);swap(s1,s2);
		}
		ll dltD=0,dltS=0;
		for(int i=1;i<M1;i++)dltD-=Day(Y1,i);dltD-=D1-1;
		for(int i=1;i<M2;i++)dltD+=Day(Y2,i);dltD+=D2-1;
		dltD+=sum[Y2]-sum[Y1];
		dltS=3600*(h2-h1)+60*(m2-m1)+(s2-s1);
		printf("%lld\n",86400*dltD+dltS);
	}
	return 0;
}
