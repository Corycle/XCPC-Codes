#include <bits/stdc++.h>
using namespace std;
#define int long long
class node
{
    public:
    int l,r,t;
    bool operator< (const node& rhs) const
    {
        return l<rhs.l;
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    vector<node> vt;
    for(int i=1;i<=m;++i)
    {
        int t,l,r;
        cin>>t>>l>>r;
        vt.push_back(node{l,r,t});
    }
    sort(vt.begin(),vt.end());


    int tt = 0;


    if(vt[0].t==2)
    {
        cout<<"0/21/0";
        return 0;
    }

    reverse(vt.begin(),vt.end());

    int shit = 0;

    int tot =0;

    for(auto i:vt)
    {
        if(i.l==1)
        {
            if(i.r==1)
            {
                break;
            }
            i.l=2;
        }
        if(i.t==2)
        {
            shit += i.r-i.l+1;
            tot+=i.r-i.l+1;
        }
        else
        {
            int tmp = i.r-i.l+1;
            if(tmp<=shit)
            {
                shit-=tmp;
                tot+=tmp*3;
            }
            else
            {
                tot += shit*3;
                tmp -=shit;
                shit = tmp%2;
                tot += (tmp/2)*3 +(tmp-tmp/2);
                if(shit) tt=1;
            } 
        }
    }
    
    int orz = (shit/2*2+1)*3;

    if(tt) orz= min(orz, ((shit+1)/2*2)*3 + 4);

    tot += orz;

    cout<<tot;

    return 0;
}