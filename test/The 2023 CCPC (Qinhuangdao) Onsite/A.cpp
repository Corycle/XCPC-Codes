#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
set<pair<int,int> >s;
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        printf("%d %d\n",i,i);
        printf("%d %d\n",i,i%n+1);
        s.insert(make_pair(i,i));
        s.insert(make_pair(i,i%n+1));
    }
    for(int j=2*n+1,x=1,y=1;j<=k;++j,++y,(y>n?(y=1,++x):0)){
        if(s.find(make_pair(x,y))!=s.end()){
            ++k;
            continue;
        }
        printf("%d %d\n",x,y);
    }
}