#include<bits/stdc++.h>
using namespace std;
class String{
public:
    char *array;
    int len;
    char tmp;
    String(int Len=0,char *Array=NULL):len(Len),array(Array){}
    String(const char *p){
        len=strlen(p);
        array=new char[len+1];
        strcpy(array,p);
        array[len]='\0';
    }
    String(const String& A){
        len=A.len;
        array=new char[len+1];
        strcpy(array,A.array);
        array[len]='\0';
    }
    ~String(){
        if(array!=NULL)delete []array;
    }
    char& operator[](int index){
        if(index>=len){
            puts("Index out of range.");
            return tmp;
        }
        return array[index];
    }
    friend ostream& operator<<(ostream &output,const String &A){
        output<<A.array;
        return output;
    }
    String& operator+(String &A){
        int newlen=len+A.len;
        char *p=new char[newlen+1];
        strcpy(p,array);
        strcpy(p+len,A.array);
        len=newlen;
        p[newlen]='\0';
        delete []array;
        array=p;
        return *this;
    }
    friend String operator+(String A,const char *p){
        String C;
        C.len=A.len+strlen(p);
        C.array=new char[C.len+1];
        strcpy(C.array,A.array);
        strcpy(C.array+A.len,p);
        C.array[C.len]='\0';
        return C;
    }
    operator int(){
        return len;
    }
};
int main(){
    String string1("mystring"),string2("yourstring"),string3("herstring");
    cout<<string1<<endl;
    string1[7]='n';
    cout<<string1<<endl;
    string1[8]='n';
    cout<<string1+string2+string3<<endl;
    cout<<string1<<endl;
    cout<<string2+"ab"<<endl;
    cout<<string2<<endl;
    cout<<string3+3<<endl;
    cout<<string3<<endl;
    return 0;
}