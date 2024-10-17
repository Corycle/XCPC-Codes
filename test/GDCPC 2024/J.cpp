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


    if(vt[0].t==2)
    {
        cout<<"0/21/0";
        return 0;
    }

    int chance = 0;

    int time =0;
    
    int energy = 0;

    for(auto i:vt)
    {
        time += i.r-i.l+1;
        if(i.t==2)
        {
            int tmp = i.r-i.l+1;
            int rem = tmp-energy;

            energy = -rem;

            if(rem<=0) continue;
            
            int cc= min( (rem+1)/2,chance);
            chance -= cc;

            time += cc*2;

            rem -= cc * 2;

            energy = -rem;

            if(rem<=0) continue;

            time += (rem+1)/2*6;

            energy = rem%2;
        }
        else
        {
            int tmp = i.r-i.l+1;
            int rem = tmp-energy;
            chance += tmp;

            energy = -rem;

            if(rem<=0) continue;

            int cc= min( (rem+1)/2,chance);
            chance -= cc;

            time += cc*2;

            rem -= cc * 2;

            energy = -rem;

            if(rem<=0) continue;

            time += (rem+1)/2*6;

            energy = rem%2;
        }

        //cout<<"t "<<time<<endl;
    }

    cout<<time;

    return 0;
}