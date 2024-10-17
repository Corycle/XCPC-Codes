#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("shit.in","w",stdout);
    srand(time(0));
    cout<<"50 50"<<endl;
    for(int i=1;i<=50;++i)
    {
        for(int j=1;j<=50;++j)
        {
            cout<<rand()%2<<" ";
        }
        cout<<endl;
    }
}