//
// Created by monte on 13/11/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listadpl.h"


struct tipoitem {
    char* nome;
    unsigned int matricula;
    char* endereco;
};

struct tipolistadpl {
    TipoItem* item;
    TipoListaDpl* proxima;
    TipoListaDpl* anterior;
};

TipoListaDpl *Insere(TipoItem *aluno, TipoListaDpl *lista) {
    TipoListaDpl *nova = (TipoListaDpl *) malloc(sizeof(TipoListaDpl));
    nova->item = aluno;
    nova->proxima = lista;
    nova->anterior = NULL;
    if (lista != NULL) {
        lista->anterior = nova;
    }

    return nova;
}

TipoItem *InicializaTipoItem(char *nome, int matricula, char *endereco) {
    TipoItem *nova = (TipoItem *) malloc(sizeof(TipoItem *));

    nova->matricula = matricula;
    nova->nome=strdup(nome);
    nova->endereco=strdup(endereco);

    return nova;
}

TipoListaDpl *Retira(TipoListaDpl *lista, char *nome) {
    for (TipoListaDpl* p=lista; p!=NULL ; p = p->proxima) {
        if (strcmp(p->item->nome, nome) == 0) {
            if (p == lista){
                lista = p->proxima;
                if (p->proxima != NULL) {
                  p->proxima->anterior = p->anterior;
                }
            } else if (p->proxima == NULL){
                p->anterior->proxima = p->proxima;
            } else {
                p->proxima->anterior = p->anterior;
                p->anterior->proxima = p->proxima;
            }
            break;
        }
    }
    return lista;
}

void Imprime(TipoListaDpl *lista) {
    for (TipoListaDpl* p=lista; p!=NULL ; p = p->proxima) {
        printf("%s | %d | %s",
                p->item->nome,
                p->item->matricula,
                p->item->endereco);
        printf("\n");
    }
}

TipoListaDpl *libera(TipoListaDpl *lista) {
    for (TipoListaDpl* p=lista; p!=NULL ; p = p->proxima) {
        free(p->item->endereco);
        free(p->item->nome);
        free(p->item);
        if (p->anterior != NULL) {
            free(p->anterior);
        }
    }

    return NULL;
}

