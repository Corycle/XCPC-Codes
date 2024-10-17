#include<bits/stdc++.h>
#include<sys/types.h>
#include<sys/wait.h>
using namespace std;
int main(){
    pid_t pid;
    pid=fork();
    if(pid<0){
        cerr<<"Fork failed!"<<endl;
        return 1;
    }
    if(!pid){
        cout<<"The pid of child process is "<<getpid()<<endl;
        execlp("/bin/ls","ls","-l",NULL);
    }
    else{
        cout<<"The pid of father process is "<<getpid()<<endl;
        wait(NULL);
        cout<<"Child process complete!"<<endl;
    }
    return 0;
}