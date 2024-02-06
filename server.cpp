/**
 * @file server.cpp
 * @author Kerolos Mikhail
 * @brief A C++ file to contain definitions of
 *        Server class methods
 *
 * @version 0.1
 * @date 2023-10-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "server.hpp"
#include <cstring>


Server::Server(uint16_t port) : port(port)
{
    std::memset(&server_addr, 0, sizeof(server_addr)); // Clear structure
}

void Server::open_socket()
{
    server_fd = socket(AF_INET, SOCK_STREAM, ANY_PROTOCOL);

    if(server_fd < 0){
        error("Failed to open socket!");
    }

    server_addr.sin_family = AF_INET;
     // Convert port from host byte order to network byte order 
    // and store the result in the structure
    server_addr.sin_port = htons(port);

    // Convert IP from host byte order to network byte order 
    // and store the result in the structure
    // inet_pton(AF_INET, IP, &(server_addr.sin_addr));
    server_addr.sin_addr.s_addr = INADDR_ANY;
    addr_len = sizeof(server_addr);

    if(bind(server_fd, (struct sockaddr*)(&server_addr), addr_len)< 0){
        error("Failed to bind!");
    }

    listen(server_fd, LISTEN_BACKLOG);
    std::cout << "Server is listening now" << std::endl;

}

uint32_t Server::accept_client()
{
    new_socket_fd = accept(server_fd, (struct sockaddr*)(&client_addr), (socklen_t*)&addr_len);
    if(new_socket_fd < 0){
        error("Failed to accept client connection!"); 
    }

    std::cout << "server is now connected to " << inet_ntoa(client_addr.sin_addr) << std::endl;
    return new_socket_fd;
}

void Server::receive_msg(std::string& buffer)
{

    if((read(new_socket_fd, msg_buf, sizeof(msg_buf)-1)) < 0){
        error("Failed to receive message!");
    }

    std::cout << "Message received: " << msg_buf << std::endl;
    std::strcpy(buffer.data(), msg_buf);
    // clear message buffer
    std::memset(msg_buf, 0, sizeof(msg_buf));
}

void Server::send_msg(const char* message)
{
    if(send(new_socket_fd, message, strlen(message), 0) < 0){
        error("Failed to send message!");
    }

}

void Server::close_client_socket()
{
    close(new_socket_fd);
    std::cout << "......Closing Client Socket......" << std::endl;
}

void Server::close_server_socket()
{
    close(server_fd);
    std::cout << "......Closing Server Socket......" << std::endl;
}

Server::~Server(){}
        