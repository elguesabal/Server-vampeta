#include "header.h"

/// @brief INICIA O CARTAO SD E CASO O CARTAO NAO ESTEJA PRESENTE ESPERA ATE UM CARTAO SER INSERIDO
void sdStart(void) {
    SPI.begin(SCK, MISO, MOSI, CS);
    if (!SD.begin(CS, SPI, 25000000)) {
        #if defined(M5CARDPUTER)
            M5CARDPUTER.println("Aguardando insercao do carta SD...");
        #endif
        while (!SD.begin(CS, SPI, 25000000)) {
            delay(1000);
        }
        #if defined(M5CARDPUTER)
            M5CARDPUTER.println("Cartao SD inserido");
        #endif
    }
}

/// @brief VERIFICA SE EXISTE UMA PASTA OU ARQUIVO
/// @param path CAMINHO COMPLETO A SRE VERIFICADO
bool checkPath(const char *path) {
    return (SD.exists(path));
}

/// @brief VERIFICA SE O CARTAO SD CONTINUA PRESENTE E CASO TENHA SIDO REMOVIDO PAUSA O PROGRAMA ATE UM CARTAO SER INSERIDO
void checkSD(void) {
    if (!SD.open("/")) {
        #if defined(M5CARDPUTER)
            M5CARDPUTER.println("Aguardando insercao do carta SD...");
        #endif
        while (!SD.open("/")) {
            delay(1000);
        }
        #if defined(M5CARDPUTER)
            M5CARDPUTER.println("Cartao SD inserido");
        #endif
    }
}