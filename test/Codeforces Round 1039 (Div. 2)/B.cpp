#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,l,r,a[N],b[N],lst;
void Update1(){
    if(l==r){
        printf("L");
        return;
    }
    if(a[l]<=a[r])printf("RL");
    else printf("LR");
    l++;r--;
    lst=1;
}
void Update2(){
    if(l==r){
        printf("L");
        return;
    }
    if(a[l]<=a[r])printf("LR");
    else printf("RL");
    l++;r--;
    lst=0;
}
signed main(){
    int T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++){
            a[i]=read();
        }
        l=1;r=n;m=0;lst=0;
        for(int i=1;i<=n;i++){
            if(lst==0){
                Update1();
                ++i;
            }
            else {
                Update2();
                ++i;
            }
        }
        puts("");
    }
    return 0;
}