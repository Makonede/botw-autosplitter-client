#include "split_timer.hpp"

#include <megaton/prelude.h>

#include <KingSystem/ActorSystem/actAiInlineParam.h>

void SplitTimer::enter_(ksys::act::ai::InlineParamPack* params) {
    bool hook = params->getParam(params->findIndex(
        "Hook", ksys::AIDefParamType::Bool
    )).b;
    uintptr_t hook_address = params->getParam(params->findIndex(
        "HookAddress", ksys::AIDefParamType::Int
    )).i;
    u32 delay_frames = params->getParam(params->findIndex(
        "DelayFrames", ksys::AIDefParamType::Int
    )).u;

    // TODO
}
