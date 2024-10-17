#include<bits/stdc++.h>
using namespace std;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
double dispp(double x,double y,double xx,double yy){
	return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}
double dis(double x,double y,double xx1,double yy1,double xx2,double yy2){
	if((xx2-xx1)*(x-xx1)+(yy2-yy1)*(y-yy1)<0) return dispp(x,y,xx1,yy1);
	if((xx1-xx2)*(x-xx2)+(yy1-yy2)*(y-yy2)<0) return dispp(x,y,xx2,yy2);
	double A = yy1-yy2;
	double B = xx2-xx1;
	double C = xx1*yy2-xx2*yy1;
//	printf("%lf %lf %lf %lf %lf %lf %lf\n",x,y,xx1,yy1,xx2,yy2,fabs(A*x+B*y+C)/sqrt(A*A+B*B));
	return fabs(A*x+B*y+C)/sqrt(A*A+B*B);
	
}
int n,q,x[5050],y[5050];
double tmp[4];
int main(){
	n=read();q=read();
	for(int i=1;i<=n;++i) x[i]=read(),y[i]=read();
	x[0]=x[n];y[0]=y[n];
	while(q--){
		for(int i=0;i<4;++i) tmp[i]=read();
		double xc=(tmp[0]+tmp[2])/2;
		double yc=(tmp[1]+tmp[3])/2;
		double R2=((tmp[0]-xc)*(tmp[0]-xc)+(tmp[1]-yc)*(tmp[1]-yc));
		bool flag=true;
		for(int i=0;i<n;++i) if((x[i]-xc)*(y[i+1]-yc)-(y[i]-yc)*(x[i+1]-xc)<0) flag=false;
		if(flag){
			printf("%.10lf\n",R2/2);
			continue;
		}
		double d=1e18;
		for(int i=0;i<n;++i){
			d=min(d,dis(xc,yc,x[i],y[i],x[i+1],y[i+1]));
//			cout<<q<<' '<<d<<' '<<dis(xc,yc,x[i],y[i],x[i+1],y[i+1])<<endl;
		}
		printf("%.10lf\n",d*d+R2/2);
	}
}
