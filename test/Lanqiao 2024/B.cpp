#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int Check(){
	for(int i=1;i<=5;i++){
		int flag=1;
		for(int j=1;j<=5;j++)if(a[i][j]!=a[i][1])flag=0;
		if(flag==1)return 0;
		flag=1;
		for(int j=1;j<=5;j++)if(a[j][i]!=a[1][i])flag=0;
		if(flag==1)return 0;
	}
	int flag=1;
	for(int i=1;i<=5;i++)if(a[i][i]!=a[1][1])flag=0;
	if(flag==1)return 0;
	flag=1;
	for(int i=1;i<=5;i++)if(a[i][6-i]!=a[1][5])flag=0;
	if(flag==1)return 0;
	return 1;
}
int main(){
	int ans=0;
	for(int i=0;i<(1<<25);i++){
		int num=0;
		for(int j=0;j<25;j++)num+=((i>>j)&1);
		if(num!=13)continue;
		for(int x=1;x<=5;x++){
			for(int y=1;y<=5;y++){
				int id=(x-1)*5+y;
				a[x][y]=(i>>(id-1))&1;
			}
		}
		ans+=Check();
	}
	cout<<ans<<endl;
	return 0;
}
