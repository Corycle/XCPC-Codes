#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=n-m+1;i<=n;++i) printf("%d ",i);
	return 0;
}
