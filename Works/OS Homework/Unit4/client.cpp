#include<bits/stdc++.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#define PORT 1145
#define BUFFER_SIZE 1024
using namespace std;

int main(){
    int client_socket=socket(AF_INET,SOCK_STREAM,0);
    if(client_socket<0){
        cerr<<"Failed to create client socket."<<endl;
        return 1;
    }
    sockaddr_in client_addr;
    client_addr.sin_family=AF_INET;
    client_addr.sin_port=htons(PORT);
    client_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    connect(client_socket,(sockaddr*)&client_addr,sizeof(client_addr));

    double x;
    cout<<"Please input a number x."<<endl;
    cin>>x;

    char buffer[BUFFER_SIZE];
    memset(buffer,0,sizeof(buffer));
    snprintf(buffer,sizeof(buffer),"%.8lf",x);
    write(client_socket,buffer,sizeof(buffer));

    memset(buffer,0,sizeof(buffer));
    read(client_socket,buffer,sizeof(buffer));
    double answer=atof(buffer);
    cout<<answer<<endl;

    close(client_socket);
    return 0;
}