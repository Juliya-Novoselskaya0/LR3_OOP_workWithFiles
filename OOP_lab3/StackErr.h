#pragma once


#include <iomanip> // для setw
#include <iostream>
//using namespace std;
class StackErr
{
    char message[50];
public:
    StackErr(char* s)
    {
        strcpy_s(message, s);
    }
    void show()
    {
        std::cout << message << std::endl;
    }
};
