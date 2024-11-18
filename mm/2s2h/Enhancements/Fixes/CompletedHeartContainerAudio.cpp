#include <libultraship/bridge.h>
#include "2s2h/GameInteractor/GameInteractor.h"

extern "C" {
#include "variables.h"
}

void RegisterCompletedHeartContainerAudio() {
    REGISTER_VB_SHOULD(VB_COMPLETED_HEART_CONTAINER_AUDIO_FIX, {
        GetItemId getItemId = va_arg(args, GetItemId);
        if (CVarGetInteger("gEnhancements.Fixes.CompletedHeartContainerAudio", 0) && getItemId == GI_HEART_PIECE &&
            GET_QUEST_HEART_PIECE_COUNT == 0) {
            *should = true;
        }
    });
}
