#include<bits/stdc++.h>
using namespace std;
const int maxn=3e6+6;
int fuck[maxn];
string tbd;
int lst[maxn];
bool check(int l,int r)
{
    //cout<<"t "<<l<<" "<<r<<endl;
    int a[2];
    a[0]=0;
    a[1]=0;
    for(int i=l;i<r;i=lst[i]+1)
    {
        if(tbd[i]=='(')
        {
            a[0]++;
        }
        else
        {
            a[1]++;
        }
        if(i+1>lst[i]-1)
        {
            continue;
        }
        if(check(i+1,lst[i]-1))
        {
            return true;
        }
    }
    return (a[0]>=2||a[1]>=2);
}
void work(){
    tbd="";
    string s;
    cin>>s;
    fuck['(']=fuck[')']=1;
    fuck['[']=fuck[']']=2;
    fuck[1]='(';
    fuck[2]='[';
    fuck[3]=')';
    fuck[4]=']';
    int n = s.size();
    for(int i=0;i<n+5;++i) lst[i] = INT_MAX;
    vector<pair<int,int> > vt;
    for(int i=0;i<n;++i)
    {
        int sym = fuck[s[i]];
        if(vt.size()&&vt.back().first==sym)
        {
            lst[vt.back().second]=i;
            vt.pop_back();
            tbd.push_back(fuck[sym+2]);
        }
        else
        {
            vt.emplace_back(sym,i);
            tbd.push_back(fuck[sym]);
        }
    }
    if(!vt.empty())
    {
        cout<<"No\n";
        return;
    }
    //cout<<"test "<<tbd<<endl;
    if(check(0,tbd.size()-1))
    {
        cout<<"No\n";
    }
    else
    {
        cout<<"Yes\n";
    }
}
int main(){
    ios::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--) work();
}