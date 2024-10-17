#include <bits/stdc++.h>
using namespace std;
#define int long long
void mian()
{
    vector<int> v[20];
    v[2].push_back(1);
    v[3].push_back(2);
    v[4].push_back(3);
    for(int i=1;i<=12;++i)
    {
        int a,b;
        cin>>a>>b;
        int index=0;
        for(int j=1;j<20;++j)
        {
            for(auto k:v[j])
            {
                if(k==a)
                {
                    index = j;
                }
            }
        }
        int mov = max(0ll,index+b);
        int fuck = 0;
        for(auto& j:v[index])
        {
            if(j == a) fuck =1;
            if(fuck)
            {v[mov].push_back(j);j=0;}
        }
        while(v[index].size()&&v[index].back()==0)
        {
            v[index].pop_back();
        }
        //cout<<index<<endl;
        //for(int i=0;i<20;++i) cout<<v[i].size()<<" ";
        //cout<<endl;
    }
    cout<<(v[9].size()==3?"Y\n":"N\n");
}
signed main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=0;i<t;++i)
    {
        mian();
    }
}