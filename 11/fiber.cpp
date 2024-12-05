#include "fiber.h"
#include <cstdlib>

constexpr size_t STACK_SIZE = 100'000;

Fiber::Fiber(std::function<void()> f)
    : f(std::move(f))
    , stack(calloc(STACK_SIZE, 1))
{}

Fiber::~Fiber() {
    free(stack);
}

void Fiber::Run() {
    f();
}

intptr_t Fiber::GetStack() {
    return reinterpret_cast<intptr_t>(stack) + STACK_SIZE - sizeof(intptr_t);
}