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
char s[N];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
	while(T--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		int flag=0;
		for(int i=1;i<=n;i++){
			if(i!=1&&s[i]==s[i-1]){
				printf("%c%c\n",s[i-1],s[i]);
				flag=1;
				break;
			}
			if(i>2&&s[i]!=s[i-1]&&s[i]!=s[i-2]&&s[i-1]!=s[i-2]){
				printf("%c%c%c\n",s[i-2],s[i-1],s[i]);
				flag=1;
				break;
			}
		}
		if(!flag)puts("-1");
	}
	return 0;
}
