#include <bits/stdc++.h>
using namespace std;
#define int long long
map<char,int> mp; 
void mian()
{
    mp['N'] = 0;
    mp['E'] = 1;
    mp['S'] = 2;
    mp['W'] = 3;
    int n;
    cin>>n;

    int init = 0;

    vector<pair<int,int> > vt;

    int F = 0;
    
    for(int i=1;i<=n;++i)
    {
        string s;
        int x;
        cin>>s>>x;
        int fuck = mp[s[0]];
        vt.push_back(make_pair((fuck+4-init)%4,x));
        init = fuck;
        if(i==1)
        {
            F = s[0];
            vt[0].first = 0;
        }
    }

    mp[0] = 'N';
    mp[1] = 'E';
    mp[2] = 'S';
    mp[3] = 'W';

    vector<pair<char,int> > ops;

    for(auto i:vt)
    {
        if(i.first==0)
        {
            ops.emplace_back('Z',i.second);
        }
        else if(i.first==1)
        {
            ops.emplace_back('R',-1);
            ops.emplace_back('Z',i.second);
        }
        else
        {
            ops.emplace_back('L',-1);
            ops.emplace_back('Z',i.second);
        }
    }
    cout<<ops.size()<<" "<<(char)(F)<<"\n";

    for(auto i:ops)
    {
        cout<<i.first;
        if(i.second>=0) cout<<" "<<i.second;
        cout<<"\n";
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;++i) mian();
}
