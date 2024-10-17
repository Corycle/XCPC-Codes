#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n;
int main(){
    cin>>n;
    int ans=1;
    for(int i=1;i<=n;i++)ans=1ll*ans*i%Mod;
    printf("%d\n",ans);
    return 0;
}