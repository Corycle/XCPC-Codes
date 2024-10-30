#include<bits/stdc++.h>
using namespace std;
int n,m,l1,r1,l2,r2;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if((r1-l1+1>=10)||(r2-l2+1>=10)){puts("9");}
        else{
            int ans=0;
            for(int i=l1;i<=r1;i++){
                for(int j=l2;j<=r2;j++){
                    int x=i+j;
                    while(x){
                        ans=max(ans,x%10);
                        x/=10;
                    }
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}