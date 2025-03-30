#pragma once

#include <KingSystem/ActorSystem/actionDummyAction.h>

class SplitTimer : public ksys::act::ai::DummyAction {
    SEAD_RTTI_OVERRIDE(SplitTimer, ksys::act::ai::DummyAction)

public:
    explicit SplitTimer(const InitArg& arg);
    void enter_(ksys::act::ai::InlineParamPack* params) override;
};
