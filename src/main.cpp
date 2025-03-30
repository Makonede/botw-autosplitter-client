#include <megaton/hook.h>

#include "split_timer.hpp"
#include "utility.hpp"

static ksys::act::ai::DummyAction** action_pointer = nullptr;

struct hook_inline_(find_action) {
    target_offset_(0x1597cd8)
    static void call(megaton::hook::InlineCtx* ctx) noexcept {
        // Extract the double pointer to the DummyAction created for SplitTimer
        // w0 is the CRC-32 hash of the name of the action
        // x22 is mClasses.begin()
        // w21 is the index of the class in mClasses
        if (!action_pointer && ctx->w<0>() == 0x25e063fe /* SplitTimer */)
            action_pointer = reinterpret_cast<ksys::act::ai::DummyAction**>(
                ctx->x<22>()
            ) + ctx->w<21>();
    }
};

[[noreturn]] auto main_thread([[maybe_unused]] auto* unused) noexcept {
    while (!action_pointer) yield();
    const auto* dummy = *action_pointer;
    auto* split_timer = new SplitTimer({
        .actor = dummy->getActor(),
        .def_idx = dummy->getDefinitionIdx(),
        .root_idx = -1,
    });
    *action_pointer = split_timer;
    while (true) yield();
}

extern "C" void megaton_main() noexcept {
    find_action::install();
    start_thread(main_thread);
}
