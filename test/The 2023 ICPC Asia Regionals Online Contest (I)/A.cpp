#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,cnt1,cnt2,cnt3;
string s[10004],t[10004],S[10004],T[10004],ss[10004];
map<string,bool> vis1,vis2,vis3;
int main(){
    n=read();m=read();
    for(int i=1;i<=n;++i) cin>>S[i];
    for(int i=1;i<=m;++i) cin>>T[i];
    for(int i=1;i<=n;++i){
    	if(!vis1[S[i]]){
    		vis1[S[i]]=true;
    		s[++cnt1]=S[i];
		}
	}
    for(int i=1;i<=m;++i){
    	if(!vis2[T[i]]){
    		vis2[T[i]]=true;
    		t[++cnt2]=T[i];
		}
	}
    for(int i=1;i<=min(cnt1,cnt2);++i){
    	ss[++cnt3]=s[i];
    	ss[++cnt3]=t[i];
    }
    for(int i=min(cnt1,cnt2)+1;i<=cnt1;++i)
    	ss[++cnt3]=s[i];
    
    for(int i=min(cnt1,cnt2)+1;i<=cnt2;++i)
    	ss[++cnt3]=t[i];
    for(int i=1;i<=cnt3;++i){
    	if(!vis3[ss[i]]){
    		vis3[ss[i]]=true;
    		cout<<ss[i]<<'\n';
		}
	}
    return 0;
}
