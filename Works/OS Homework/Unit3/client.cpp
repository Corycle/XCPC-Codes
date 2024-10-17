#include<bits/stdc++.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define PORT 1145
using namespace std;
int main(){
    // 创建客户端套接字
    int Socket=socket(AF_INET, SOCK_STREAM, 0);
    if(Socket==-1){
        cerr<<"Create socket failed"<<endl;
        return 1;
    }
	sockaddr_in Address;
    Address.sin_family=AF_INET;// 使用 IPv4
    Address.sin_port=htons(PORT);// 设置端口号为
    Address.sin_addr.s_addr=inet_addr("127.0.0.1");// 设置 IP 地址
    connect(Socket, (sockaddr*)&Address, sizeof(Address));// 绑定接口
    
    char Word[20]={0},Answer[20]={0};
    cout<<"Please input an English word."<<endl;
    cin>>Word;
    write(Socket,Word,sizeof(Word));
    read(Socket,Answer,sizeof(Answer));
    cout<<Answer<<endl;

    close(Socket);

	return 0;
}
