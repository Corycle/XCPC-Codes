#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;char c=getchar();
    while((c<'0'||c>'9')&&c!='-') c=getchar();
    if(c=='-') f=-1,c=getchar();
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return f*x;
}
void work(){
    int n=read();
    vector<int> v1,v2;
    for(int i=1;1ll*i*i<=n;++i){
        if(n%i==0){
            v1.push_back(i);
            v2.push_back(n/i);
        }
    }
    reverse(v2.begin(),v2.end());
    int n1 = v1.size(), n2 = v2.size();
    long long ans = 0;
    for(int i=0;i<n1-1;++i){
        ans += 1ll*n/v1[i]*(v1[i+1]-v1[i]);
    }
    ans += 1ll*n/v1[n1-1]*(v2[0]-v1[n1-1]);
    for(int i=0;i<n2-1;++i){
        ans += 1ll*n/v2[i]*(v2[i+1]-v2[i]);
    }
    ans+=1;
    printf("%lld\n",ans);
}
int main(){
    int T=read();
    while(T--) work();
}