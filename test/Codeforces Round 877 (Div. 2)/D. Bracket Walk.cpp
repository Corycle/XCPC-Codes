/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m;
char s[N];
set<int>p1,p2;
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();m=read();scanf("%s",s+1);
    if(n&1){while(m--)puts("NO");return 0;}
    for(int i=1;i<n;i++){
        if(s[i]=='('&&s[i+1]=='(')p1.insert(i);
        if(s[i]==')'&&s[i+1]==')')p2.insert(i);
    }
    while(m--){
        int x=read();
        if(x!=n&&s[x]=='('&&s[x+1]=='(')p1.erase(x);
        if(x!=1&&s[x-1]=='('&&s[x]=='(')p1.erase(x-1);
        if(x!=n&&s[x]==')'&&s[x+1]==')')p2.erase(x);
        if(x!=1&&s[x-1]==')'&&s[x]==')')p2.erase(x-1);
        s[x]=(s[x]=='('?')':'(');
        if(x!=n&&s[x]=='('&&s[x+1]=='(')p1.insert(x);
        if(x!=1&&s[x-1]=='('&&s[x]=='(')p1.insert(x-1);
        if(x!=n&&s[x]==')'&&s[x+1]==')')p2.insert(x);
        if(x!=1&&s[x-1]==')'&&s[x]==')')p2.insert(x-1);
        
        if(s[1]!='('||s[n]!=')'){puts("NO");continue;}

        if(p1.empty()&&p2.empty()){puts("YES");continue;}
        if(p1.empty()||p2.empty()){puts("NO");continue;}
        set<int>::iterator l1=p1.begin(),l2=--p1.end();
        set<int>::iterator r1=p2.begin(),r2=--p2.end();
        if((*l1)<(*r1)&&(*l2)<(*r2))puts("YES");
        else puts("NO");
    }
	return 0;
}
