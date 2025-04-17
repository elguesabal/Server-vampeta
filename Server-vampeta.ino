#include "header.h"

DNSServer *dns = nullptr;
WebServer *frontEnd = nullptr;
WebServer *backEnd = nullptr;

void setup(void) {
    cardputerStart();
    sdStart();
    acessPointerStart();
    dnsStart();
    frontEndStart();
    backEndStart();
}

void loop(void) {
    checkSD();
    dns->processNextRequest();
    #if defined(PORT_FRONT_END)
        frontEnd->handleClient();
    #endif
    #if defined(PORT_BACK_END)
        backEnd->handleClient();
    #endif
    delay(2);
}