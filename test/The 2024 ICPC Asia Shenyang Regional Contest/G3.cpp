#include<bits/stdc++.h>
using namespace std;
int n,m;
set<int> xs;
vector<int> vx;
void Answer(double ans){
    int area2 = round(2*ans);
    if(area2%2==0) cout<<"! "<<area2/2<<" 1"<<endl;
    else cout<<"! "<<area2<<" 2"<<endl;
}
vector<double> sumer;
void work1(){
    double len=0,lstlen,ans=0;
    for(int i=1;i<n-1;++i){
        lstlen=len;
        cout<<"? "<<vx[i]<<" 1"<<endl;
        double x,y;cin>>x>>y;len=x/(double)y;
        sumer.push_back((len+lstlen)/2*(vx[i]-vx[i-1]));
    }
    sumer.push_back(len/2*(vx[n-1]-vx[n-2]));
    sort(sumer.begin(),sumer.end());
    for(auto x:sumer) ans+=x;
    Answer(ans);
}
void work2(){
    double ans=0;
    for(int i=1;i<m;++i){
        int midx2 = vx[i]+vx[i-1];
        if(midx2%2==0) cout<<"? "<<midx2/2<<" 1"<<endl;
        else cout<<"? "<<midx2<<" 2"<<endl;
        double x,y;cin>>x>>y;double len=x/(double)y;
        sumer.push_back(len*(vx[i]-vx[i-1]));
    }
    sort(sumer.begin(),sumer.end());
    for(auto x:sumer) ans+=x;
    Answer(ans);
}
void work3(){
    int x[10],y[10];
    for(int i=1;i<=3;++i){
        cin>>x[i]>>y[i];
    }
    x[1]-=x[3]; y[1]-=y[3];
    x[2]-=x[3]; y[2]-=y[3];
    int area = abs(x[1]*y[2]-y[1]*x[2]);
    Answer(area/2.0);
}
void work(){
    cin>>n; xs.clear(); vx.clear(); sumer.clear();
    if(n==3) {work3();return;}
    for(int i=1;i<=n;++i){
        int x,y;
        cin>>x>>y;
        xs.insert(x);
    }
    m=(int)xs.size();
    for(auto x:xs) vx.push_back(x);
    if(m==n) work1();
    else work2();
}
signed main(){
    int T;
    cin>>T;
    while(T--) work();
}