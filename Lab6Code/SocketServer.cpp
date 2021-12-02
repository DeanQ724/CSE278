// Server side C/C++ program to demonstrate Socket programming
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>
#include <thread>
#include <vector>
#define PORT 8080

using namespace std;

int CountClients=0;
bool Working=true;
vector<thread> threads;
vector<int> Sockets;
void thread_Server(int Sock)
{
    printf("Connected to Client!\n");
    char buffer[1024] = {0};
    int  valread;
    while (Working)
    {
        valread = read( Sock + 1  , buffer, 1024);
        if (valread>=0)
        {
            //cout<<buffer<<endl;
            for (int sockClient: Sockets)
            {
                if (Sock==sockClient) continue;
                if(buffer[0] == 's' && buffer[1] == 't' && buffer[2] == 'o' && buffer[3] == 'p'){
                    exit(1);
                }
                send(sockClient , buffer , valread , 0 );
                cout<<buffer;
            }
            
        }
        
    }
}


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
            cout<<buffer<<endl;
        }
        
    }
}


int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    const char *hello = "Hello from server";
       
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
       
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;//INADDR_ANY or INADDR_LOOPBACK
    address.sin_port = htons( PORT );


    //add by me
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &address.sin_addr)<=0) 
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    
       
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, 
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    while (true)
    {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                       (socklen_t*)&addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        else
        {
            CountClients++;
            Sockets.push_back(new_socket);
            threads.push_back(thread(thread_Server,new_socket));
        }

    }
    for(auto& thread: threads)
        {
            thread.join();
        }
    
    return 0;
}