#pragma once

#include <KingSystem/ActorSystem/actAiAction.h>

namespace uking::action {
    class SplitTimer : public ksys::act::ai::Action {
        SEAD_RTTI_OVERRIDE(SplitTimer, ksys::act::ai::Action)

    public:
        explicit SplitTimer(const InitArg& arg);
        ~SplitTimer() override;

        bool init_(sead::Heap* heap) override;
        void enter_(ksys::act::ai::InlineParamPack* params) override;
        void leave_() override;
        void loadParams_() override;

    protected:
        void calc_() override;

        bool* hook{};
        int* hook_address{};
        int* delay_frames{};
    };
}
