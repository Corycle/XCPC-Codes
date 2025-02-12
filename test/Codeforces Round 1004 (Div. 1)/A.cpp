#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,cnt,a[N],vis[N];
int Query(int x,int y){
    cout<<"? "<<x<<" "<<y<<endl;
    int t;
    cin>>t;
    return t;
}
int main(){
    srand(time(NULL));
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            vis[i]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
            vis[a[i]]=1;
        }
        int x=0;
        for(int i=1;i<=n;i++){
            if(!vis[i])x=i;
        }
        if(x){
            int y=a[x];
            int t1=Query(x,y);
            int t2=Query(y,x);
            if(t1!=0){
                cout<<"! B"<<endl;
                continue;
            }
            else{
                cout<<"! A"<<endl;
                continue;
            }
        }
        else{
            int y=0;
            for(int i=1;i<=n;i++){
                if(a[i]==1)x=i;
                if(a[i]==n)y=i;
            }
            int t1=Query(x,y);
            int t2=Query(y,x);
            if(!t1||!t2){
                cout<<"! A"<<endl;
                continue;
            }
            if(t1==t2&&t1>=abs(a[x]-a[y])){
                cout<<"! B"<<endl;
                continue;
            }
            else{
                cout<<"! A"<<endl;
                continue;
            }
        }
    }
    return 0;
}