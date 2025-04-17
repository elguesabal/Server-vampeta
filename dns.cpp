#include "header.h"

void dnsStart(void) {
    dns = new DNSServer();
    dns->start(PORT_DNS, DOMAIN, WiFi.softAPIP());
    #if defined(M5CARDPUTER)
       M5CARDPUTER.print("Hostname: ");
       M5CARDPUTER.println(DOMAIN);
    #endif
}