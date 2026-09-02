#include <iostream>
#include <string>

// Эта программа для Hello World с персонализацией
// Удален using namespace std

int main()
{
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello world from " << name << std::endl;
    return 0;
}
