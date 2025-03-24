#include "header.h"

WebServer *frontEnd = nullptr;
WebServer *backEnd = nullptr;

void setup(void) {
    cardputerStart();
    sdStart();
    acessPointerStart();
    frontEndStart();
    backEndStart();
}

void loop(void) {
    checkSD();
    #if defined(PORT_FRONT_END)
        frontEnd->handleClient();
    #endif
    #if defined(PORT_BACK_END)
        backEnd->handleClient();
    #endif
    delay(2);
}