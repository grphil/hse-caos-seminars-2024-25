#include <iostream>

#include "scheduler.h"

int main() {
    AddFunc([]() { // f1
        std::cout << 1 << std::endl;
        Yield();
        std::cout << 3 << std::endl;
    });

    AddFunc([]() { // f2
        std::cout << 2 << std::endl;
        Yield();
        std::cout << 4 << std::endl;
    });

    RunFuncs();
}
