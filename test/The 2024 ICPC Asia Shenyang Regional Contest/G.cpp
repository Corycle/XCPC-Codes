#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<int> vt;
void mian2(){
    long double area = 0;
    vector<long double> q;
    for(int i=1;i<n;++i){
        if(vt[i]==vt[i-1]) continue;
        int x = vt[i]+vt[i-1];
        if(x&1) cout<<"? "<<x<<" 2"<<endl;
        else cout<<"? "<<x/2<<" 1"<<endl;
        double xx,yy;long double len;cin>>xx>>yy;len=xx/(long double)yy;
        q.push_back(len*(vt[i]-vt[i-1]));
    }

    sort(q.begin(),q.end());
    for(auto x:q) area+=x;

    int nmb = (int)((2*area)+0.5);

    cout<<"! ";
    if(nmb%2 == 1)
    {
        cout<<nmb<<" 2\n";
    }
    else
    {
        cout<<nmb/2<<" 1\n";
    }
    cout.flush();
}
void mian1()
{
    long double fuck = 0;
    long double last = 0;

    vector<long double> q;
    for(int i=1;i+1<vt.size();++i)
    {
        cout<<"? "<<vt[i]<<" 1\n";
        cout.flush();
        double x,y;
        cin>>x>>y;
        long double shit = ((long double)x)/y;
        q.push_back((last+shit)*(vt[i]-vt[i-1])/2);
        // fuck = fuck + (last+shit)*(vt[i]-vt[i-1])/2;
        last = shit;
    }
    q.push_back((last)*(vt[n-1]-vt[n-2])/2);
    // fuck = fuck + (last)*(vt[n-1]-vt[n-2])/2;

    sort(q.begin(),q.end());
    for(auto x:q) fuck+=x;

    int nmb = (int)((2*fuck)+0.5);

    cout<<"! ";
    if(nmb%2 == 1)
    {
        cout<<nmb<<" 2\n";
    }
    else
    {
        cout<<nmb/2<<" 1\n";
    }
    cout.flush();
}
void input(){
    cin>>n;
    vt.clear();
    for(int i=1;i<=n;++i)
    {
        int x,y;
        cin>>x>>y;
        vt.push_back(x);
    }
    sort(vt.begin(),vt.end());
    bool flag = true;
    for(int i=1;i<n;++i) if(vt[i]==vt[i-1]) flag=false;
    if(flag) mian1();
    else mian2();
}
signed main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        input();
    }
    return 0;
}