#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n=inf.readInt(1,3000,"n");
    inf.readSpace();
    int m=inf.readInt(1,20000,"m");
    inf.readEoln();
    for(int i=1;i<=m;i++){
        int x=inf.readInt(1,n,"x");
        inf.readSpace();
        int y=inf.readInt(1,n,"y");
        inf.readSpace();
        int z=inf.readInt(1,100000,"z");
        inf.readEoln();
    }
    inf.readEof();
}