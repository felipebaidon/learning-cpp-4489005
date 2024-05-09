// Learning C++ 
// Exercise 01_02
// Hello World, by Eduardo Corpeño 

#include <iostream>
#include <string>

int main(void)
{
    std::string str;

    std::cout << "Enter your name: " << std::flush;
    std::cin >> str;

    std::cout << "Nice to meet you, " << str << std::endl;

    std::cout << std::endl << std::endl;

    return 0;
}