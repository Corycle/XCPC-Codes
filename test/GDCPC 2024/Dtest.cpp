#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
long long n;
struct Ans{
    int l,r,k;
    bool operator<(const Ans &b) const {
        if(k==b.k) return l+r<b.l+b.r;
        return k<b.k;
    }
}
int calc(int x,int y){}
int main(){
    cin>>n;
    for(int l=1;l<=n;++l){
        for(int r=l;r<=n;++r){
            ans.push(Ans{l,r,calc(l,r)});
        }
    }
    cout<<ans.top().l<<' '<<ans.top().r<<' '<<ans.top().k;
}