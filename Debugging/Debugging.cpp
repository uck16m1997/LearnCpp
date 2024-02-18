// Debugging.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void testFunc(int x);

int main()
{
    std::cout << "Learn Debugging!\n";

    int x{};
    testFunc(x);
    std::cout << "Result " <<  x << "\n";
}

void testFunc(int x) {
    x = 20;

}