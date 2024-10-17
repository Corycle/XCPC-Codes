#include<iostream>
using namespace std;
int qpow(int a,int b,int c){
	int ans=1,base=a%c;
	for(int i=1;i<=b;i<<=1){
		if(b&i) ans=ans*base%c;
		base=base*base%c;
	}
	return ans;
} 
int n;
int Calc(int n){
	int cnt=0;
	for(int i=1;i<=n*n-n;++i)
		for(int j=1;j<=n*n-n;++j)
			if(qpow(i,j,n)==qpow(j,i,n))
				/*cout<<i<<' '<<j<<endl,*/++cnt;
	return cnt;
}
bool Prime(int x){
	if(x<=1)return false;
	for(int i=2;i*i<=x;i++){
		if(x%i==0)return false;
	}
	return true;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		cout<<Calc(n)<<endl;
	}
	return 0;
	for(int i=1;i<=n;i++)if(Prime(i))cout<<i<<" "<<Calc(i)<<endl;
	return 0;
} 
