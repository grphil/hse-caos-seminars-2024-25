#pragma once

#include <cstdint>

struct Context {
    intptr_t rsp;
    intptr_t rip;

    void SwitchContext();
};