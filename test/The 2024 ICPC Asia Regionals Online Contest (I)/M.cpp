#include<bits/stdc++.h>
using namespace std;
const int M=30;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
string s1,s2,s3;
int n,m;
unordered_map<string,bool>S[M];
void Clear(){
    for(int i=0;i<M;i++)S[i].clear();
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s1>>s2>>s3;
            if(s3=="accepted")S[s2[0]-'A'+1][s1]=true;
        }
        int Max=0,ans=0;
        for(int i=0;i<M;i++){
            int num=S[i].size();
            if(num>Max){
                Max=num;
                ans=i;
            }
        }
        printf("%c\n",ans+'A'-1);
        Clear();
    }
    return 0;
}