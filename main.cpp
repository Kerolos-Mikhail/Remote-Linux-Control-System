/**
 * @file main.cpp
 * @author Kerolos Mikhail
 * @brief This is the main program to 
 *        control PC from API on remote host
 *
 * @version 0.1
 * @date 2023-10-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <arpa/inet.h>
#include <cstdint>
#include <iostream>
#include <thread>
#include "server.hpp"
#include "system_shell.hpp"

#define PORT    5050

void new_client(void);

Server hostmachine(PORT);
System_Shell terminal;
std::string message;

int main()
{
  uint32_t temp_fd = 0;

  hostmachine.open_socket();

  while(true){

    temp_fd = hostmachine.accept_client();
    
    std::thread connect(new_client);
    connect.join();
  }

  hostmachine.close_server_socket();
    
  return 0;
}

void new_client(){
   
   char input;

  while(true){
      
    hostmachine.receive_msg(message);
    terminal.run_command(message.data());

    // hostmachine.send_msg("I got message");      
    std::cout << "Do you want to end connection with " << inet_ntoa(hostmachine.client_addr.sin_addr) << 
    " ? (y,n): ";
    std::cin >> input;

    if(input == 'y'){
      hostmachine.close_client_socket();
      break;
    }      
  }
}