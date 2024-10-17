#include<bits/stdc++.h>
using namespace std;
int n,m;
pair<int,int> o[100005];
int read(){
    int x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x;
}
void work(){
    n=read();m=read();
    for(int i=1;i<=m;++i) o[i].first=read(),o[i].second=read();
    sort(o+1,o+m+1);
    if(o[1].second>o[1].first) {puts("No");return;}
    for(int i=2;i<=m;++i){
        if(o[i].second<=o[i].first-o[i-1].first-1) continue;
        if(o[i].second-o[i-1].second==o[i].first-o[i-1].first) continue;
        puts("No"); return;
    }
    puts("Yes");
}
int main(){
    int T=read();
    while(T--) work();
}