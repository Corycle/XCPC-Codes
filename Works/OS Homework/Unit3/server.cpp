#include<bits/stdc++.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define PORT 1145
using namespace std;
map<string, string>Dic={
    {"fruit","水果"},
    {"apple", "苹果"},
    {"banana", "香蕉"},
    {"pear", "梨"},
    {"pineapple", "菠萝"},
    {"mango", "芒果"},
    {"watermelon", "西瓜"},
    {"peach", "桃"},
    {"grape", "葡萄"}
};
int main(){
    // 创建服务端套接字
	int Socket1=socket(AF_INET, SOCK_STREAM, 0);
    if(Socket1==-1){
        cerr<<"Create socket failed"<<endl;
        return 1;
    }
    sockaddr_in Address1;
    Address1.sin_family=AF_INET;// 使用 IPv4
    Address1.sin_port=htons(PORT);// 设置端口号为
    Address1.sin_addr.s_addr=inet_addr("127.0.0.1");// 设置 IP 地址
    bind(Socket1, (sockaddr*)&Address1, sizeof(Address1));// 绑定接口
    listen(Socket1, 5);// 监听请求

    while(1){
        // 处理客户端请求
        sockaddr_in Address2;
        socklen_t Len = sizeof(Address2);
        int Socket2 = accept(Socket1, (sockaddr*)&Address2, &Len);
        cout << "The connection is from " << inet_ntoa(Address2.sin_addr) << endl;

        char words[20]={0};
        read(Socket2,words,sizeof(words));
        string Word=words,Answer="";
        if(Dic.find(Word)!=Dic.end()){
            Answer=Dic[Word];
        }
        else Answer="The word doesn't exist in the dictionary.";
        write(Socket2,Answer.c_str(),Answer.length());
        close(Socket2);
    }
    close(Socket1);
	return 0;
}
