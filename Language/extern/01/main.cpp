#include "extern.h"
#include <iostream>
int a;

int main (int argc, char* argv[])
{
    a = 10;

    std::cout << a << std::endl;

    a = 5;

    print_a();
    return 0;
}