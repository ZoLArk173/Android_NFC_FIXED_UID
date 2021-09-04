//
// Created by joe on 19-1-2.
//

#include "logging.hpp"
#include "hook.hpp"

const char LOG_TAG[] = "UIDCTRL:main ==> ";


void __attribute__ ((constructor)) main_entry() {
    // init Log Singleton instance with verbose info level
    Log::getInstance(Log::LOG_LEVEL_INFO);

/*********************************test logical*********************************/
    Log &log = Log::getInstance();
    log.print(Log::LOG_LEVEL_INFO, LOG_TAG, "entry in");
    Hook &hook = Hook::getInstance(true);
    hook.hook();
    if(hook.isHooked()){
        uint8_t uid[4] = {0x00, 0x01, 0x02, 0x03}; // four byte NFCID1
        hook.setNfcId(uid);
    }
    log.print(Log::LOG_LEVEL_INFO, LOG_TAG, "entry out");
/*********************************test logical*********************************/

    return;
}
