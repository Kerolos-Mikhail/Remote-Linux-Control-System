# Remote Linux Control System

## Introduction
The Remote Linux Control System is an innovative solution designed to enable users to remotely execute commands and manage a Linux-based system from a remote device. Utilizing C++ and socket programming.

## Features
- **Command Execution:** Execute Linux commands remotely with real-time feedback.
- **User-Friendly Interface:** Easy-to-use command interface for efficient remote management.
- **Cross-Platform Compatibility:** Client application can be run from any device supporting C++ execution.

## Installation

### Prerequisites
- Linux-based system for the server.
- C++ development environment for compiling the source code.

### Compilation
g++ -o server main.cpp server.cpp system_shell.cpp -lpthread
