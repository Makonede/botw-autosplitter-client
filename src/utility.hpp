#pragma once

#include <memory>

#include <cstdlib>

#include <megaton/prelude.h>

#include <nn/os.h>

template <typename T = void>
inline auto start_thread(void (*func)(void*), T* const arg = nullptr) noexcept {
    constexpr auto STACK_SIZE = 0x80000uz;
    constexpr auto ALIGNMENT = 0x1000uz;
    constexpr auto PRIORITY = 16;
    auto thread = std::make_unique<nn::os::ThreadType>();
    auto* stack = aligned_alloc(ALIGNMENT, STACK_SIZE);

    if (!stack) return;
    if (nn::os::CreateThread(
        thread.get(), func, arg, stack, STACK_SIZE, PRIORITY
    ).IsFailure()) return std::free(stack);
    nn::os::StartThread(thread.release());
}

inline auto yield(u64 time = 100'000'000) noexcept {
    nn::os::SleepThread(nn::TimeSpan::FromNanoSeconds(time));
}
