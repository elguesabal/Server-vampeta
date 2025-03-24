#include "header.h"

/// @brief INICIA O FRONT END E DEFINE AS ROTAS
/// @brief COMO AS OUTRAS ROTAS ALEM DO HOME SAO DEFINIDAS PELA EXISTENCIA DE UM ARQUIVO NO SD QUALQUER OUTRA ROTA ACONTECE NO METODO "onNotFound"
void frontEndStart(void) {
    #if !defined(PORT_FRONT_END)
        #if defined(M5CARDPUTER)
            M5CARDPUTER.println("Front end nao iniciado");
        #endif
        return ;
    #else
        frontEnd = new WebServer(PORT_FRONT_END);
    #endif
    if (!checkPath(PATH_FRONT_END)) {
        #if defined(M5CARDPUTER)
            M5CARDPUTER.println("Pasta \"" + String(PATH_FRONT_END) + "\" ausente (Front end nao iniciado)");
        #endif
        return ;
    }
    routesFrontEnd();
    frontEnd->begin();
    #if defined(M5CARDPUTER) && defined(PORT_FRONT_END)
        M5CARDPUTER.printf("Front end iniciado na porta %d\n", PORT_FRONT_END);
    #endif
}

/// @brief INICIA AS ROTAS DO FRONT END
void routesFrontEnd(void) {
    frontEnd->on("/", home);
    frontEnd->onNotFound(getRoute);
}

/// @brief RESPONDE A ROTA HOME CASO TENHA O ARQUIVO "/PATH_FRONT_END/index.html"
/// @warning CASO A PAGINA NAO SEJA ENCONTRADA RESPONDE COM O STATUS 404 "NOT FOUND"
/// @note CASO TUDO OCORRA CORRETAMENTE RESPONDE COM STATUS 200 "OK"
void home(void) {
    File file = SD.open(String(PATH_FRONT_END) + "/index.html");

    if (!file) {
        frontEnd->send(404, "text/plain", "Erro 404: Pagina home nao existe (adicione um arquivo \"index.html\" na pasta \"" + String(PATH_FRONT_END) + "\")");
        return ;
    }
    frontEnd->streamFile(file, "text/html");
    file.close();
}

/// @brief PROCURA O ARQUIVO (OU PAGINA HTML) SEGUINDO A URL PASSADA NA ROTA E CASO NAO EXISTA O ARQUIVO CITADO ENVIA UMA MENSAGEM DE ERRO
/// @warning CASO A PAGINA NAO SEJA ENCONTRADA RESPONDE COM O STATUS 404 "NOT FOUND"
/// @note CASO TUDO OCORRA CORRETAMENTE RESPONDE COM STATUS 200 "OK"
void getRoute(void) {
    String path = PATH_FRONT_END + cutUrl(frontEnd->uri(), '?') + (cutUrl(frontEnd->uri(), '?').indexOf(".") == -1 ? ".html" : "");
    String type = getType(path);
    File file = SD.open(path);

    if (!file) {
        frontEnd->send(404, "text/plain", "Erro 404: \"" + frontEnd->uri() + "\" nao encontrado");
        return ;
    }
    frontEnd->streamFile(file, type);
    file.close();
}