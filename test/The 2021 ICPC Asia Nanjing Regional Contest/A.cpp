#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    if(a<=n/2&&b<=n/2){
        for(int i=1;i<n;i++)putchar('L');
        for(int i=1;i<n;i++)putchar('U');
        for(int i=1;i<a;i++)putchar('D');
        for(int i=1;i<b;i++)putchar('R');
    }
    else if(a<=n/2&&b>n/2){
        for(int i=1;i<n;i++)putchar('R');
        for(int i=1;i<n;i++)putchar('U');
        for(int i=1;i<a;i++)putchar('D');
        for(int i=1;i<=n-b;i++)putchar('L');
    }
    if(a>n/2&&b<=n/2){
        for(int i=1;i<n;i++)putchar('L');
        for(int i=1;i<n;i++)putchar('D');
        for(int i=1;i<=n-a;i++)putchar('U');
        for(int i=1;i<b;i++)putchar('R');
    }
    if(a>n/2&&b>n/2){
        for(int i=1;i<n;i++)putchar('R');
        for(int i=1;i<n;i++)putchar('D');
        for(int i=1;i<=n-b;i++)putchar('L');
        for(int i=1;i<=n-a;i++)putchar('U');
    }
    return 0;
}