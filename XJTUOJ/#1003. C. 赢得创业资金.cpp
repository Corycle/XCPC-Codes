/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1005;
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
		int n=strlen(s+1),flag1=0,flag2=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='n'&&s[i+1]=='b'){
				if(!flag1){flag2=1;break;}
				i++;flag1=0;
			}
			else flag1=1;
		}
		if(flag1||flag2)puts("NO");
		else{
			printf("YES ");
			for(int i=1;i<=n;i++){
				if(s[i]=='n'&&s[i+1]=='b'){printf(" ");i++;}
				else printf("%c",s[i]);
			}
			puts("");
		}
	}
	return 0;
}
