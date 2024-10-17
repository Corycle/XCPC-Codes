#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
char s[N],t[N];
int main(){
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        scanf("%s%s",s+1,t+1);
        int n=strlen(s+1),m=strlen(t+1);
        int num=0;
        for(int j=1;j<=min(n,m);j++){
            if(s[j]==t[j])num++;
            else break;
        }
        if(!num)printf("%d\n",n+m);
        else printf("%d\n",n+m-num+1);
    }
    return 0;
}