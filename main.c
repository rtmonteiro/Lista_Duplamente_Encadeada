#include <stdio.h>
#include <stdlib.h>
#include "listadpl.h"

int main() {

    TipoListaDpl* lista = (TipoListaDpl*)malloc(sizeof(TipoListaDpl));

    TipoItem* ryan = InicializaTipoItem("Ryan", 2019202359, "rua 1");
    TipoItem* lenke = InicializaTipoItem("Lenke", 2019202149, "rua 2");
    TipoItem* pedro = InicializaTipoItem("Pedro", 2019101213, "rua 3");

    lista = Insere(ryan, lista);
    lista = Insere(lenke, lista);
    lista = Insere(pedro, lista);

    Imprime(lista);
    return 0;
}