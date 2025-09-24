#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	if(n<=m)
	{
		for(int a=0;a<=n;++a)
		{
			for(int b=0;b<=m;++b)
			{
				int tmp = -1;
				for(int x=max(0,a+b-m);x<=min(n,a+b);++x)
				{
					int R = min({m,n-a+b,n+b-x,m-a+x});
					int L = max({0,b-a,b-x,x-a});
					tmp += max(0,R-L+1);
					//cout<<"shit "<<x<<" "<<L<<" "<<R<<endl;
				}
				cout<<tmp<<" ";
			}
			cout<<"\n";
		}
	}
	else
	{
		swap(n,m);
		for(int b=0;b<=m;++b)
		{
			for(int a=0;a<=n;++a)
			{
				int tmp = -1;
				for(int x=max(0,a+b-m);x<=min(n,a+b);++x)
				{
					int R = min({m,n-a+b,n+b-x,m-a+x});
					int L = max({0,b-a,b-x,x-a});
					tmp += max(0,R-L+1);
					//cout<<"shit "<<x<<" "<<L<<" "<<R<<endl;
				}
				cout<<tmp<<" ";
			}
			cout<<"\n";
		}
	}

}
