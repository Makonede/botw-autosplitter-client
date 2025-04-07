#pragma once

#include <KingSystem/ActorSystem/actAiAction.h>

class SplitTimer : public ksys::act::ai::Action {
    SEAD_RTTI_OVERRIDE(SplitTimer, ksys::act::ai::Action)

public:
    explicit SplitTimer(const InitArg& arg);
    void enter_(ksys::act::ai::InlineParamPack* params) override;
};
