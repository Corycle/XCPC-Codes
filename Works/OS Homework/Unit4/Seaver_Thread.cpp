#include<bits/stdc++.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#define PORT 1145
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
using namespace std;
double F(double x){
    return sqrt(x);
}
void *Calc(void *arg){
    int client_socket=*(int*)arg;
    char buffer[BUFFER_SIZE];

    memset(buffer,0,sizeof(buffer));
    read(client_socket,buffer,sizeof(buffer));
    double x=atof(buffer);

    memset(buffer,0,sizeof(buffer));
    snprintf(buffer,sizeof(buffer),"%.8lf",F(x));
    write(client_socket,buffer,sizeof(buffer));

    close(client_socket);
    pthread_exit(NULL);
}
int main(){
    int seaver_socket=socket(AF_INET,SOCK_STREAM,0);
    if(seaver_socket<0){
        cerr<<"Failed to create seaver socket."<<endl;
        return 1;
    }
    sockaddr_in seaver_addr;
    seaver_addr.sin_family=AF_INET;
    seaver_addr.sin_port=htons(PORT);
    seaver_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    bind(seaver_socket,(sockaddr*)&seaver_addr,sizeof(seaver_addr));
    listen(seaver_socket,MAX_CLIENTS);

    while(1){
        sockaddr_in client_addr;
        socklen_t client_len=sizeof(client_addr);
        int client_socket=accept(seaver_socket,(sockaddr*)&client_addr,&client_len);
        if(client_socket<0){
            cerr<<"Failed to accept client socket."<<endl;
            continue;
        }
        
        pthread_t tid;
        if(pthread_create(&tid,NULL,Calc,&client_socket)!=0){
            cerr<<"Failed to create new thread."<<endl;
            close(client_socket);
            continue;
        }

        cout<<"The connection is from "<<inet_ntoa(client_addr.sin_addr)<<endl;
        cout<<"The thread ID is "<<tid<<endl;
    }
    close(seaver_socket);
    return 0;
}