#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
ll gcd(ll a,ll b){while(a) a^=b^=a^=b%=a; return b;}
struct Node{
    ll x,y;
    Node(ll a,ll b):x(a),y(b){}
    void Update(){
        ll c=gcd(x,y);x/=c;y/=c;
    }
    friend bool operator<(Node A,Node B){
        return (__int128)A.x*B.y-A.y*B.x<0;
    }
};
int main(){
    int T=read();
    while(T--){
        ll x=read();
        ll pos=sqrt(x*2);
        Node ans(x+1,2);
        ans.Update();
        for(ll i=max(pos-1,1ll);i<=min(pos+1,x);i++){
            Node tmp(2*x+i*i-i,2*i);
            tmp.Update();
            if(tmp<ans)ans=tmp;
        }
        ans.Update();
        printf("%lld %lld\n",ans.x,ans.y);
    }
    return 0;
}