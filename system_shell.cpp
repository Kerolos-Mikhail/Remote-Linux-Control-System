/**
 * @file system_shell.cpp
 * @author Kerolos Mikhail
 * @brief A C++ program to contain definitions of
 *        System_Shell class methods 
 * @version 0.1
 * @date 2023-10-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "system_shell.hpp"
#include <sys/types.h>


void System_Shell::run_command(char* command)
{
    // pid_t pid = fork();

    // if(pid == -1){
    //     std::cerr << "Failed to create new process!" << std::endl;
    //     std::exit(EXIT_FAILURE);
    // }

    if(std::system(command) == -1){
        std::cerr << "Failed to execute command!" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    else{
        std::cout << "Command is executed successfully!" << std::endl;
    }
}

System_Shell::~System_Shell(){}
