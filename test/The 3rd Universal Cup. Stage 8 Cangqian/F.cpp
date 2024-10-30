#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int a[N],cnt[N],r[N];
char s[N][25];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s%d",s[i]+1,&a[i]);
        cnt[a[i]]++;
    }
    for(int i=10;i>=1;i--)cnt[i]+=cnt[i+1];
    bool flag=0;
    printf("Stage: ");
    for(int i=1;i<=n;i++){
        int num=strlen(s[i]+1)-cnt[a[i]+1]-1;
        for(int j=1;j<=num;j++){
            if(!flag){
                putchar(s[i][j]-'a'+'A');
                flag=1;
            }
            else putchar(s[i][j]);
        }
    }
    return 0;
}