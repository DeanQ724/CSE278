// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#define PORT 8080
#include <thread>   

using namespace std;

bool Working=true;

void thread_Send(int sock)
{
    printf("Please enter a line:\n");
    char *line = NULL;
    size_t len = 0;
    ssize_t lineSize = 0;
    while (Working)
    {
        lineSize = getline(&line, &len, stdin);
        send(sock , line , lineSize , 0 );
    }
    
    
}

void thread_Receive(int Sock)
{
    char buffer[1024] = {0};
    int  valread;
    while (Working)
    {
        valread = read( Sock , buffer, 1024);
        if (valread>0)
        {
            cout<<buffer;
        }
        if(buffer[0+3] == 's' && buffer[1+3] == 't' && buffer[2+3] == 'o' && buffer[3+3] == 'p'){
                    exit(1);
        
    }
    
}

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    const char *hello = "Hello from client";
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
   
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
       
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    
    thread Thread_send_Obj(thread_Send,sock);
    thread Thread_Receive_Obj(thread_Receive,sock);
    
    Thread_send_Obj.join();
    Thread_Receive_Obj.join();
    
    return 0;
}