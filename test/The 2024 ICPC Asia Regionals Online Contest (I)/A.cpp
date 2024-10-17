#include <bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int> a[233];
void mian()
{
    for(int i=1;i<=32;++i)
    {
        cin>>a[i].first;
        a[i].first = a[i].first;
        a[i].second = i;
    }

    sort(a+1,a+33);

    for(int i=1;i<=32;++i)
    {
        if(a[i].second == 1 && i < 3)
        {
            cout<<"32\n";
            return;
        }
        if(a[i].second == 1 && i < 7)
        {
            cout<<"16\n";
            return;
        }
        if(a[i].second == 1 && i < 14)
        {
            cout<<"8\n";
            return;
        }
        if(a[i].second == 1 && i < 28)
        {
            cout<<"4\n";
            return;
        }

        if(a[i].second == 1 && i < 32)
        {
            cout<<"2\n";
            return;
        }

        if(a[i].second == 1 && i == 32)
        {
            cout<<"1\n";
            return;
        }
    }

    
}
signed main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;++i) mian();
    return 0;
}