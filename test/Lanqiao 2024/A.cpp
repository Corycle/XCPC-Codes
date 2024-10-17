#include<bits/stdc++.h>
using namespace std;
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int b[10]={13,1,2,3,5,4,4,2,2,2};
int Count(int y,int m,int d){
	return b[y%10]+b[y/10%10]+b[y/100%10]+b[y/1000]+b[m%10]+b[m/10]+b[d%10]+b[d/10];
}
int main(){
	int flag=0,ans=0;
	for(int Y=2000;Y<=2024;Y++){
		for(int M=1;M<=12;M++){
			int dmax=a[M]+(Y%4==0&&M==2);
			for(int D=1;D<=dmax;D++){
				if(Count(Y,M,D)>50)ans++;
				if(Y==2024&&M==4&&D==13){flag=1;break;}
			}
			if(flag)break;
		}
		if(flag)break;
	}
	cout<<ans<<endl;
	return 0;
}
