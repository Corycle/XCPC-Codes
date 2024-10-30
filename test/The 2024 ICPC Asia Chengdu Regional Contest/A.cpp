#include <bits/stdc++.h>
using namespace std;
#define int long long
void mian()
{
    string s;
    cin>>s;
    int n=s.size();
    s=" "+s+"  ";
    if(s[1]!='>'||s[n]!='>'||s[n-1]!='>'||s[n-2]!='>')
    {
        cout<<"No\n";
        return;
    }
    int nt=0;
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='-')
        {
            nt=i;
        }
    }
    if(nt==0)
    {
        cout<<"No\n";
        return;
    }
    int cnt = 0;
    //cout<<"Yes\n";
    vector<pair<int,int> > vt;
    for(int i=n-2;i>nt;--i)
    {
        cnt++;
        //cout<<1<<" "<<i+2<<"\n";
        vt.emplace_back(1ll,i+2);
    }
    for(int i=1;i<nt;++i)
    {
        if(s[i]=='>')
        {
            cnt++;
            //cout<<i<<" "<<nt+4-i<<"\n";
            vt.emplace_back(i,nt+4-i);
        }
    }
    cout<<"Yes "<<cnt<<"\n";
    for(auto i:vt)
    {
        cout<<i.first<<" "<<i.second<<"\n";
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        mian();
    }
    return 0;
}