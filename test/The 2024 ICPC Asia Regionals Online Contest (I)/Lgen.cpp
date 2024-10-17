#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("shit.in","w",stdout);
    cout<<1<<endl;
    cout<<"2000 2000 1000000\n";
    for(int i=1;i<=2000;++i)
    {
        for(int j=1;j<=2000;++j)
        {
            int x = (j/50)+48;
            int y = (j%50) +48;
            cout<<(char)x<<(char)y;
        }
        cout<<"\n";
    }
    for(int i=1;i<=1000000;++i)
    {
        cout<<"010101\n";
    }
}