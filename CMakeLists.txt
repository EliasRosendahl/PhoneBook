cmake_minimum_required(VERSION 3.9)
project(PhoneBook C)

set(CMAKE_C_STANDARD 99)

add_executable(PhoneBook main.c contacts.c contacts.h main.h)