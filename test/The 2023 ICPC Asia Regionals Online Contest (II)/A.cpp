#include <bits/stdc++.h>
using namespace std;
const int maxn=15000+5;
int a[maxn];
vector<int>v;
int pre[maxn];
	string s="";
	int xpos[maxn];

int print(int num,int pos){
	if(num==0) return pos;
	if(num&1){
		string s1,s2,s3;
		s1=(string)"s(s("+s[pos++]+"))";
		s2=(string)"s(s("+s[pos++]+"))";
		s3=(string)"s(s("+s[pos++]+"))";
		
		printf("%s+(%s+%s)*(",s1.c_str(),s2.c_str(),s3.c_str());
		pos=print(num>>1,pos);
		printf(")");
	}
	else{
		string s1,s2;
		s1=(string)"s(s("+s[pos++]+"))";
		s2=(string)"s(s("+s[pos++]+"))";
		printf("(%s+%s)*(",s1.c_str(),s2.c_str());
		pos=print(num>>1,pos);
		printf(")");
	}
	return pos;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		string s1;
		cin>>s1;
		s+=s1;
	}
//	for(int i=1;i<maxn;++i)
//	{
//		s=s+"x";
//	}
//	n=maxn;
	int k;
	cin>>k;
	for(int i=1;i<=k;++i)
	{
		int x;
		cin>>x;
		cin>>pre[x];
	}
	pre[0]=1;
	for(int i=9;i>=1;--i)
	{
		pre[i]=pre[i]-pre[i-1];
	}
	int tot=1;
	for(int i=1;i<n;)
	{
		if(s[i]=='x')
		{
			i+=150;
			xpos[tot++]=i;
		}
		else ++i;
	}
//	for(int i=1;i<=9;++i) cout<<xpos[i]<<' ';
	xpos[0]=-151;
	for(int i=1;i<=9;++i){
		if(i!=1) cout<<"*";
		cout<<"s(s(s(s(s(";
		for(int j=xpos[i-1]+151;j<xpos[i];++j){
			if(j!=xpos[i-1]+151) cout<<"+";
			cout<<s[j];
		}
		cout<<")))))";
		string s1="",s2,s3,s4,s5;
		int nowpos=xpos[i];
		for(int j=0;j<9-k;++j) s1+=(string)"+s(s("+s[j+nowpos]+"))";
		nowpos+=9-k;
		s2=(string)"s(s("+s[nowpos++]+"))";
		s3=(string)"s(s("+s[nowpos++]+"))";
		s4=(string)"s(s("+s[nowpos++]+"))";
		s5=(string)"s(s("+s[nowpos++]+"))";
		printf("+(s(s((x%s)*(%s+%s)-%s))-%s)*(",s1.c_str(),s2.c_str(),s3.c_str(),s4.c_str(),s5.c_str());
		if(pre[i]<=0){
			string s6;
			s6=(string)"s(s("+s[nowpos++]+"))";
			printf("%s-",s6.c_str());
			pre[i]=1-pre[i];
		}
		nowpos=print(pre[i],nowpos);
		printf(")");
		cout<<"*s(s(s(s(s(";
		for(int j=nowpos;j<=xpos[i]+150;++j) {
			if(j!=nowpos) cout<<"+";
			cout<<s[j];
		}
		cout<<")))))";
	}
	for(int j=xpos[9]+151;j<n;++j) 	cout<<(string)"*s(s("<<s[j]<<"))";
	return 0;
}
