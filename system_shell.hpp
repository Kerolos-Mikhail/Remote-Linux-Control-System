/**
 * @file system_shell.hpp
 * @author Kerolos Mikhail
 * @brief A header file to contain declaration of
 *        System_Shell class for PC Control program
 *
 * @version 0.1
 * @date 2023-10-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _SYSTEM_SHELL_HPP_
#define _SYSTEM_SHELL_HPP_

#include <array>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <algorithm>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <iostream>
#include <unistd.h>

class System_Shell
{
    private:
        std::map<std::string, std::string> shell_commands {{"firefox", "firefox --new-tab"},
        {"vlc", "sudo vlc /home/kerolos/kerolos/Embedded-Linux/02C++/07_Algorthim/algorithm.mp4"},
        {"pdf", "evince /home/kerolos/kerolos/Embedded-Linux/02C++/07_Algorthim/06_Alg_RAII.pdf"}
        };

    public:
        System_Shell() = default;

        void run_command(char* command);

        ~System_Shell();
};

#endif // !_SYSTEM_SHELL_HPP_