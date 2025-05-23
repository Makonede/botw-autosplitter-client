#include "split_timer.hpp"

#include <megaton/prelude.h>

#include <KingSystem/ActorSystem/actAiInlineParam.h>

SplitTimer::SplitTimer(const InitArg& arg) : ksys::act::ai::Action(arg) {}

void SplitTimer::enter_(ksys::act::ai::InlineParamPack* params) {
    const bool hook = params->getParam(params->findIndex(
        "Hook", ksys::AIDefParamType::Bool
    )).b;
    const uintptr_t hook_address = params->getParam(params->findIndex(
        "HookAddress", ksys::AIDefParamType::Int
    )).i;
    const u32 delay_frames = params->getParam(params->findIndex(
        "DelayFrames", ksys::AIDefParamType::Int
    )).u;

    // TODO
}
