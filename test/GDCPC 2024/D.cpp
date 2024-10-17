#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
long long n;
int main(){
    cin>>n;
    if(n==2){
        cout<<"1 1";
        return 0;
    }
    long long l=1,r=1,k=1,ansl,ansr;
    while(l<=n&&r<=n){
        ansl=l;
        ansr=r;
        if(k) l+=r;
        else r+=l;
        k^=1;
    }
    cout<<min(ansl,ansr)<<' '<<max(ansl,ansr);
}