#include "testlib.h"

int min(int x,int y){return x<y?x:y;}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int x=inf.readInt(1,10000,"x");
    inf.readSpace();
    int y=inf.readInt(1,10000,"y");
    inf.readSpace();
    int z=inf.readInt(0,min(x,y),"z");
    inf.readEoln();
    inf.readEof();
}