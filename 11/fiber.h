#pragma once

#include <functional>
#include <cstdint>

class Fiber {
public:
    Fiber(std::function<void()> f);

    ~Fiber();

    void Run();

    intptr_t GetStack();
private:
    std::function<void()> f;
    void* stack;
};