#include "header.h"

/// @brief COPIA A URL ATE UM DETERMINADO DELIMITADOR
/// @param url URL COMPLETA Q VAI SR COPIADA
/// @param c CARACTER Q VAI DELIMITAR A COPIA
/// @return RETORNA UMA STRING SEM O DELIMITADOR EM DIANTE E SE NAO ENCONTRAR O DELIMMITADOR RETORNA A url
String cutUrl(const String &url, char c) {
    int pos = url.indexOf(c);

    if (pos == -1) {  
        return url;
    }
    return url.substring(0, pos);
}

/// @brief BUSCA O TIPO DE ARQUIVO COM BASE NO NOME DO ARQUIVO DA REQUISICAO
/// @param file A SER ANALISADO
/// @return RETORNA O TIPO DE RESPOSTA IDEAL PARA A REQUISICAO
String getType(String file) {
    if (file.endsWith(".html")) {
        return ("text/html");
    } else if (file.endsWith(".css")) {
        return ("text/css");
    } else if (file.endsWith(".js")) {
        return ("application/javascript");
    } else if (file.endsWith(".png")) {
        return ("image/png");
    } else if (file.endsWith(".gif")) {
        return ("image/gif");
    } else if (file.endsWith(".jpg")) {
        return ("image/jpeg");
    } else if (file.endsWith(".ico")) {
        return ("image/x-icon");
    } else if (file.endsWith(".xml")) {
        return ("text/xml");
    } else if (file.endsWith(".pdf")) {
        return ("application/pdf");
    } else if (file.endsWith(".zip")) {
        return ("application/zip");
    } else if (file.endsWith(".json")) {
        return ("application/json");
    } else {
        return ("text/plain");
    }

    // TESTAR ISSO DPS
    // if (server.hasArg("download")) {
    //     return ("application/octet-stream");
    // }
}