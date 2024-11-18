#include <libultraship/bridge.h>
#include "2s2h/GameInteractor/GameInteractor.h"
#include "Enhancements/Enhancements.h"

extern "C" {
#include "variables.h"
}

void RegisterShowDekuGuardSearchBalls() {
    REGISTER_VB_SHOULD(VB_DEKU_GUARD_SHOW_SEARCH_BALLS, {
        bool isNight = va_arg(args, bool);
        uint8_t selectedOption =
            CVarGetInteger("gEnhancements.Restorations.DekuGuardSearchBalls", DEKU_GUARD_SEARCH_BALLS_NIGHT_ONLY);
        switch (selectedOption) {
            case DEKU_GUARD_SEARCH_BALLS_NEVER:
                *should = false;
                break;
            case DEKU_GUARD_SEARCH_BALLS_NIGHT_ONLY:
                *should = isNight;
                break;
            case DEKU_GUARD_SEARCH_BALLS_ALWAYS:
                *should = true;
                break;
        }
    });
}
