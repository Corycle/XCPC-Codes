#include<bits/stdc++.h>
using namespace std;
const int maxn=3e6+5;
class node
{
public:
int x,a,d,t;
}A[maxn];

set<int> fuck[10];

int seat[maxn];

    vector<node> vt;
    vector<pair<int,int> > eve;

int main(){
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int x,a,d,t;
        cin>>x>>a>>d>>t;
        A[i]=(node){x,a,d,t};
        eve.push_back(make_pair(a,i));
        eve.push_back(make_pair(d,i));
    }

    //cout<<"fuck "<<endl;


    for(int i=1;i<=(int)(1e6+5);++i)
    {
        fuck[0].insert(i);
    }

    //cout<<"shit "<<endl;


    int mx=0;


    sort(eve.begin(),eve.end());


    for(auto i:eve)
    {
        //cout<<"orz "<<endl;
        int id= i.second;
        int arr = (i.first == A[id].a);
        int type = A[id].t;
        int num = A[id].x;
        if(arr)
        {
            if(type==0)
            {
                int mn = *(fuck[0].begin());
                mx=max(mx,mn);
                fuck[0].erase(mn);
                fuck[num].insert(mn);
                seat[id] = mn;
            }
            else
            {
                int rem = 4-num;
                pair<int,int> mn ( *(fuck[0].begin()) , 0 );
                for(int j = 1;j<=rem ;++j)
                {
                    if(!fuck[j].empty())
                    {
                        mn=min(mn,make_pair(*(fuck[j].begin()), j));
                    }
                }
                mx=max(mx,mn.first);
                fuck[mn.second].erase(mn.first);
                fuck[mn.second+num].insert(mn.first);

                seat[id] = mn.first;
            }
        }
        else
        {
            for(int j =0;j<=4;++j)
            {
                if(fuck[j].count(seat[id]))
                {
                    fuck[j].erase(seat[id]);
                    fuck[j-num].insert(seat[id]);
                    break;
                }
            }
        }
        //cout<<"o"<<endl;
    }
    cout<<mx<<endl;
    return 0;
}