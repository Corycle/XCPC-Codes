#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int> > cons(int x) //2^x
{
    if(x==0)
    {
        vector<vector<int> >v;
        v.push_back(vector<int>{0});
        return v;
    }
    auto d=cons(x-1);
    vector<vector<int> >vt(1ll<<x,vector<int>(1ll<<x,0));
    int n=1ll<<x;
    int k=1ll<<(x-1);
    for(int i=0;i<k;++i)
    {
        for(int j=0;j<k;++j)
        {
            vt[i][j]=d[i][j];
        }
    }
    for(int i=0;i<k;++i)
    {
        for(int j=0;j<k;++j)
        {
            vt[n-i-1][j]=(k*k)+((k*k)-d[i][j]-1);
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<k;++j)
        {
            //cout<<"shit "<<i<<" "<<n-j-1<<" "<<j<<endl;
            vt[i][n-j-1]=(k*k*2)+((k*k*2)-vt[i][j]-1);
        }
    }
    return vt;
}
signed main()
{
    //cout<<(13&10)<<endl;
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    int k=(1ll<<__lg(n))*2;
    auto tmp=cons(__lg(k));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cout<<tmp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}