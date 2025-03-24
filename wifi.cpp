#include "header.h"

/// @brief INICIA O PONTO DE ACESSO WIFI E PRINTA NA TELA O SSID E PASSWORD
void acessPointerStart(void) {
    WiFi.mode(WIFI_AP);
    #if defined(PASSWORD)
        bool wifi = WiFi.softAP(SSID, PASSWORD);
    #else
        bool wifi = WiFi.softAP(SSID);
    #endif
    if (!wifi) {
        #if defined(M5CARDPUTER)
            M5CARDPUTER.println("Wifi nao criado");
        #endif
        while (true) {

        }
    }
    #if defined(M5CARDPUTER)
        M5CARDPUTER.printf("Ssid: %s\n", SSID);
        #if defined(PASSWORD)
            M5CARDPUTER.printf("Password: %s\n", PASSWORD);
        #endif
        M5CARDPUTER.printf("Host: %s\n", WiFi.softAPIP().toString().c_str());
    #endif
}


