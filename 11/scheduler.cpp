#include "scheduler.h"

namespace {
    Scheduler S;
}

void Scheduler::AddFunc(std::function<void()> f) {
    auto fiber = std::make_unique<Fiber>(std::move(f));
    Context context;
    context.rsp = fiber->GetStack();
    context.rip = reinterpret_cast<intptr_t>(&StartFiber);
    Fibers.emplace(std::move(fiber), context);
}

void Scheduler::Run() {
    while (!Fibers.empty()) {
        CurrentFiber = std::move(Fibers.front().fiber);
        MainContext = Fibers.front().context;
        CurrentFiberFinished = false;
        Fibers.pop();

        MainContext.SwitchContext();
        // fiber starts and runs
        // SwitchContext returns when fiber pauses

        if (!CurrentFiberFinished) {
            Fibers.emplace(std::move(CurrentFiber), MainContext);
        }
    }
}

void Scheduler::StartFiber() {
    S.CurrentFiber->Run();
    S.CurrentFiberFinished = true;
    S.MainContext.SwitchContext();
    // Unreachable
}

void Yield() {
    S.MainContext.SwitchContext();
}

void AddFunc(std::function<void()> f) {
    S.AddFunc(std::move(f));
}

void RunFuncs() {
    S.Run();
}


