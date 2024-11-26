#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
struct Node{
    int x;
    bool rep;
    double lenleps,lenreps;
    double lenl,lenr;
    double len;
};
void mian()
{
    int n,minx=100000,maxx=-100000;
    cin>>n;
    map<int,int> cnt;
    for(int i=1;i<=n;++i)
    {
        int x,y;
        cin>>x>>y;
        cnt[x]++;
        minx=min(minx,x);
        maxx=max(maxx,x);
    }
    vector<Node> v;
    for(auto x:cnt){
        v.push_back(Node{x.first,x.second>1,0});
    }
    int m = v.size();
    for(int i=0;i<m;++i){
        if(!v[i].rep){
            if(v[i].x==minx||v[i].x==maxx) {
                v[i].len=0;
        // printf("v[%d]: x=%d, rep=%d, len=%.6lf, lenleps=%.6lf, lenreps=%.6lf, lenl=%.6lf, lenr=%.6lf\n",i,v[i].x,(int)v[i].rep,v[i].len,v[i].lenleps,v[i].lenreps,v[i].lenl,v[i].lenr);
                continue;
            }
            cout<<"? "<<v[i].x<<" 1"<<endl;
            int x,y;
            cin>>x>>y;
            v[i].len=x/(double)y;
        }
        else{
            if(v[i].x==minx||v[i].x==maxx) {
                cout<<"? "<<v[i].x<<" 1"<<endl;
                int x,y;
                cin>>x>>y;
                v[i].len=x/(double)y;
                v[i].rep=false;
        // printf("v[%d]: x=%d, rep=%d, len=%.6lf, lenleps=%.6lf, lenreps=%.6lf, lenl=%.6lf, lenr=%.6lf\n",i,v[i].x,(int)v[i].rep,v[i].len,v[i].lenleps,v[i].lenreps,v[i].lenl,v[i].lenr);
                continue;
            }
            cout<<"? "<<(3*v[i].x-1)<<" 3"<<endl;
            int x,y;
            cin>>x>>y;
            v[i].lenleps=x/(double)y;
            cout<<"? "<<(3*v[i].x+1)<<" 3"<<endl;
            cin>>x>>y;
            v[i].lenreps=x/(double)y;
        }
        // printf("v[%d]: x=%d, rep=%d, len=%.6lf, lenleps=%.6lf, lenreps=%.6lf, lenl=%.6lf, lenr=%.6lf\n",i,v[i].x,(int)v[i].rep,v[i].len,v[i].lenleps,v[i].lenreps,v[i].lenl,v[i].lenr);
    }
                // long double shit = ((vt[i]-vt[lsti])*fakeshit-last/3)/((vt[i]-vt[lsti])-1/3);
                // long double shit = ((vt[i+1]-vt[i])*fakeshit-last/3)/((vt[i+1]-vt[i])-1/3);
    vector<double> areas;
    for(int i=0;i<m-1;++i){
        if(v[i].rep){
            if(v[i+1].rep){
                // puts("1");
                areas.push_back((v[i].lenreps+v[i+1].lenleps)*(v[i+1].x-v[i].x)/2);
            }
            else{
                // puts("2");
                v[i].len = ((v[i+1].x-v[i].x)*v[i].lenreps-v[i+1].len/3)/(v[i+1].x-v[i].x-1.0/3);
                areas.push_back((v[i].len+v[i+1].len)*(v[i+1].x-v[i].x)/2);
            }
        }
        else{
            if(v[i+1].rep){
                // puts("3");
                v[i+1].len = ((v[i+1].x-v[i].x)*v[i+1].lenleps-v[i].len/3)/(v[i+1].x-v[i].x-1.0/3);
                areas.push_back((v[i].len+v[i+1].len)*(v[i+1].x-v[i].x)/2);
            }
            else{
                // puts("4");
                areas.push_back((v[i].len+v[i+1].len)*(v[i+1].x-v[i].x)/2);
            }
        }
        // for(int i=0;i<m;++i) printf("v[%d]: x=%d, rep=%d, len=%.6lf, lenleps=%.6lf, lenreps=%.6lf, lenl=%.6lf, lenr=%.6lf\n",i,v[i].x,(int)v[i].rep,v[i].len,v[i].lenleps,v[i].lenreps,v[i].lenl,v[i].lenr);
    }
    double fuck = 0;
    sort(areas.begin(),areas.end());
    for(auto x:areas) fuck+=x;

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
signed main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        mian();
    }
    return 0;
}