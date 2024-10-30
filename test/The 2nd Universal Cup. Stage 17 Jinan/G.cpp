#include<bits/stdc++.h>
using namespace std;
vector<char> a[1000006];
int fa[2000006];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y){
    x=find(x);y=find(y);
    fa[x]=y;
}
void work(){
    int r,c;
    cin>>r>>c;
    for(int i=1;i<=r;++i){
        a[i].clear();
        a[i].push_back(0);
        for(int j=1;j<=c;++j){
            char ch;
            cin>>ch;
            a[i].push_back(ch);
            // cout<<ch<<endl;
        }
    }
    if(c&1){
        int num = 0;
        for(int i=1;i<=r;++i) if(a[i][(c+1)/2]=='1') ++num;
        if(num>1) {
            cout<<"0\n";
            return ;
        }
    }
    for(int i=1;i<=2*r;++i) fa[i]=i;
    for(int i=1;i<=c/2;++i){
        int j1=0,j2=0,num=0;
        for(int j=1;j<=r;++j) if(a[j][i]=='1'||a[j][c-i+1]=='1') {j1=j;break;}
        if(j1==0) continue;
        for(int j=j1+1;j<=r;++j) if(a[j][i]=='1'||a[j][c-i+1]=='1') {j2=j;break;}
        if(j2==0) continue;
        for(int j=j2+1;j<=r;++j) if(a[j][i]=='1'||a[j][c-i+1]=='1'){
            cout<<"0\n";
            return;
        }
        if(a[j1][i]=='1'&&a[j1][c-i+1]=='1') num+=2;
        else num+=1;
        if(a[j2][i]=='1'&&a[j2][c-i+1]=='1') num+=2;
        else num+=1;
        if(num>2){
            cout<<"0\n";
            return;
        }
        if(a[j1][i]==a[j2][i]){
            merge(j1,j2+r);
            merge(j1+r,j2);
        }
        else{
            merge(j1,j2);
            merge(j1+r,j2+r);
        }
    }
    int ans=0;
    for(int i=1;i<=r;i++)if(find(i)==find(i+r)){cout<<"0\n";return;}
    for(int i=1;i<=2*r;++i) if(i==fa[i]) ++ans;
    ans/=2;
    long long as=1;
    for(int i=1;i<=ans;++i) as<<=1,as%=1000000007;
    cout<<as<<"\n";
}
int main(){
    // ios::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--) work();
}