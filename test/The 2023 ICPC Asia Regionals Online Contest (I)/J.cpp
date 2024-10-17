#include<bits/stdc++.h>
using namespace std;
#define int long double
int Abs(int x)
{
	if(x<0) return -x;
	return x;
}
void mian()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int e,f,g,h;
	cin>>e>>f>>g>>h;
	pair<int,int>p1={(a+c)/2,(b+d)/2};
	pair<int,int>p2={(e+g)/2,(f+h)/2};
	int r1=sqrtl((d-b)*(d-b)+(c-a)*(c-a))/2;
	int r2=sqrtl((h-f)*(h-f)+(g-e)*(g-e))/2;
	p2.first=p2.first-p1.first;
	p2.second=p2.second-p1.second;
	p2.first=Abs(p2.first);
	p2.second=Abs(p2.second);
	int A=p2.first+p2.second;
	int k=A-sqrtl(2)*r2;
	cout<<k<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cout.precision(23);
	int t;
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		mian();
	}
	return 0;
}
