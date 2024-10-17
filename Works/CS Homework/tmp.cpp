#include<bits\stdc++.h>
#include"bmp2.h"
using namespace std;
FILE *inptr;
inline char getch(){
    static char buf[10000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,inptr),p1==p2)?EOF:*p1++;
}
int main(int argc, char *argv[]){
    char *infile = argv[1],c=0;
    inptr = fopen(infile, "rb");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }
    while(c=getch()!=EOF){
        cout<<(int)c<<" ";
    }
    return 0;
}