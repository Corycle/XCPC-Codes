/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}

int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
	while(T--){
		int n=read();
		char s[1005];
		scanf("%s",s+1);
		char c=0;
		for(int i=1;i<=n;i++){
			if(!c){
				c=s[i];
				putchar(c);
			}
			else if(c==s[i])c=0;
		}
		puts("");
	}
	return 0;
}
