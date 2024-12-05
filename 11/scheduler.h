#pragma once

#include "fiber.h"
#include "context.h"

#include <memory>
#include <queue>

class Scheduler {
public:
    Scheduler() = default;

    void AddFunc(std::function<void()> f);
    void Run();
private:
    Context MainContext;
    std::unique_ptr<Fiber> CurrentFiber;
    bool CurrentFiberFinished;

    struct FiberHolder {
        FiberHolder(std::unique_ptr<Fiber> f, Context c)
            : fiber(std::move(f))
            , context(c)
        {}

        std::unique_ptr<Fiber> fiber;
        Context context;
    };

    std::queue<FiberHolder> Fibers;


    static void StartFiber();

    friend void Yield();
};

void Yield();

void AddFunc(std::function<void()> f);

void RunFuncs();