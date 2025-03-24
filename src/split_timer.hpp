#pragma once

#include <Game/AI/Action/actionDummyAction.h>

class SplitTimer : public uking::action::DummyAction {
    SEAD_RTTI_OVERRIDE(SplitTimer, uking::action::DummyAction)

public:
    void enter_(ksys::act::ai::InlineParamPack* params) override;

protected:
    bool* hook{};
    int* hook_address{};
    int* delay_frames{};
};
