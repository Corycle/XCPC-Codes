/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
char s[N],t[N];
int a[N],b[N],flag;
bool Check(int a[],int b[]){//a<b?
	if(a[0]!=b[0])return a[0]<b[0];
	for(int i=a[0];i>=1;i--){
		if(a[i]!=b[i])return a[i]<b[i];
	}
	return false;
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	scanf("%s%s",s+1,t+1);
	a[0]=strlen(s+1);b[0]=strlen(t+1);
	for(int i=1;i<=a[0];i++)a[i]=s[a[0]-i+1]-'0';
	for(int i=1;i<=b[0];i++)b[i]=t[b[0]-i+1]-'0';
	if(Check(a,b)){flag=1;swap(a,b);}
	for(int i=b[0];i>=1;i--)a[i]-=b[i];
	for(int i=1;i<=a[0];i++){
		if(a[i]<0){a[i]+=10;a[i+1]--;}
	}
	while(a[0]>=1&&a[a[0]]==0)a[0]--;
	if(flag)printf("-");
	if(!a[0])puts("0");
	else for(int i=a[0];i>=1;i--)printf("%d",a[i]);
	return 0;
}
