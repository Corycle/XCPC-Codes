#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin>>n;
    //3*k*(k+1)<=n
    ll k=sqrt(n/3.0)-1;
    while(3*(k+1)*(k+2)<=n)k++;
    // cout<<k<<endl;
    if(3*k*(k+1)==n){
        printf("%lld %lld\n",k*2,0);
    }
    else if(3*k*(k+1)+1==n){
        printf("%lld %lld\n",k*2+1,2);
    }
    else{
        ll p=n-3*k*(k+1);
        k++;
        // cout<<p<<" "<<k<<endl;
        if(p<=k)printf("%lld %lld\n",k*2-p,2*p);
        else if(p<=k*2){
            p-=k;
            printf("%lld %lld\n",k-p*2,2*k);
        }
        else if(p<=k*3){
            p-=k*2;
            printf("%lld %lld\n",-k-p,2*k-p*2);
        }
        else if(p<=k*4){
            p-=k*3;
            printf("%lld %lld\n",-k*2+p,-2*p);
        }
        else if(p<=k*5){
            p-=k*4;
            printf("%lld %lld\n",-k+p*2,-2*k);
        }
        else{
            p-=k*5;
            printf("%lld %lld\n",k+p,-2*k+2*p);
        }
    }
    return 0;
}