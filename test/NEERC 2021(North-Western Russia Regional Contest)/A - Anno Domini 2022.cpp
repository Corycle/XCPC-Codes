#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=20;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
char s1[N],s2[N],s3[N],s4[N];
int GetNum(char s[]){
	int n=strlen(s),x=0;
	for(int i=0;i<n;i++)x=x*10+s[i]-'0';
	return x;
}
int main(){
	scanf("%s%s%s%s",s1,s2,s3,s4);
	if(s1[0]=='A'&&s3[0]=='A')printf("%d",abs(GetNum(s2)-GetNum(s4)));
	if(s2[0]=='B'&&s4[0]=='B')printf("%d",abs(GetNum(s1)-GetNum(s3)));
	if(s1[0]=='A'&&s4[0]=='B')printf("%d",GetNum(s2)+GetNum(s3)-1);
	if(s2[0]=='B'&&s3[0]=='A')printf("%d",GetNum(s1)+GetNum(s4)-1);
	return 0;
}
