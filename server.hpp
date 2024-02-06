/**
 * @file server.hpp
 * @author Kerolos Mikhail
 * @brief A header file to contain declaration of
 *        Server class for PC Control program 
 *
 * @version 0.1
 * @date 2023-10-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _SERVER_HPP_
#define _SERVER_HPP_

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <stdexcept>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#define LISTEN_BACKLOG  5
#define ANY_PROTOCOL    0

#define error(msg)  do{\
                        std::cerr << msg << std::endl;\
                        std::exit(EXIT_FAILURE);\
                    }while (0)

class Server
{
    private:
        uint32_t server_fd, new_socket_fd;
        socklen_t addr_len;
        uint16_t port {};
        const char *IP = "192.168.1.2";
        char msg_buf[256] = "";

    public:
        struct sockaddr_in server_addr, client_addr;

        Server()= delete;
        Server(uint16_t port);

        void open_socket();
        uint32_t accept_client();
        void receive_msg(std::string& buffer);
        void send_msg(const char* message);
        void close_client_socket();
        void close_server_socket();

        ~Server();

};

#endif // !_SERVER_HPP_
