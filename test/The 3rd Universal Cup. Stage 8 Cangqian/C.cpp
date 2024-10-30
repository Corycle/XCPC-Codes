#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    n=1024;m=(1+511)*511;
    printf("%d %d 2\n",n,m);
    for(int i=1;i<=512;i++)printf("1 2 ");
    puts("");
    for(int i=1;i<=512;i++){
        for(int j=1;j<i;j++){
            printf("%d %d\n",2*i-1,j*2);
            printf("%d %d\n",2*i,2*j-1);
        }
    }
    return 0;
}