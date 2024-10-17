#include<bits/stdc++.h>
using namespace std;
int n,a[2020],b[2020][2020];
int median_a(int l,int r){
    vector<int> v;
    for(int i=l;i<=r;++i) v.push_back(a[i]);
    sort(v.begin(),v.end());
    return v[(v.size()+1)/2-1];
}
int median_b(int l,int r){
    vector<int> v;
    for(int i=l;i<=r;++i)
        for(int j=i;j<=r;++j)
            v.push_back(b[i][j]);
    sort(v.begin(),v.end());
    return v[(v.size()+1)/2-1];
}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int l=1;l<=n;++l)
        for(int r=l;r<=n;++r)
            b[l][r]=median_a(l,r);
    vector<int> v;
    for(int l=1;l<=n;++l)
        for(int r=l;r<=n;++r)
            v.push_back(median_b(l,r));
    sort(v.begin(),v.end());
    cout<<v[(v.size()+1)/2-1];
}