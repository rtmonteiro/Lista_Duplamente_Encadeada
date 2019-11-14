//
// Created by monte on 13/11/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listadpl.h"

typedef struct tipocelula TipoCelula;

struct tipocelula {
    TipoItem* item;
    TipoCelula* proxima;
    TipoCelula* anterior;
};

struct tipoitem {
    char* nome;
    unsigned int matricula;
    char* endereco;
};

struct tipolistadpl {
    TipoCelula* inicio;
};

TipoListaDpl *Insere(TipoItem *aluno, TipoListaDpl *lista) {
    TipoCelula *nova = (TipoCelula *) malloc(sizeof(TipoCelula *));
    nova->item = aluno;
    nova->anterior = NULL;
    if (lista->inicio != NULL) {
        lista->inicio->anterior = nova;
        nova->proxima = lista->inicio;
    } else {
        nova->proxima = NULL;
    }
    lista->inicio = nova;

    return lista;
}

TipoItem *InicializaTipoItem(char *nome, int matricula, char *endereco) {
    TipoItem *nova = (TipoItem *) malloc(sizeof(TipoItem *));

    nova->matricula = matricula;
    nova->nome=strdup(nome);
    nova->endereco=strdup(endereco);

    return nova;
}

TipoListaDpl *Retira(TipoListaDpl *lista, char *nome) {
    for (TipoCelula* p=lista->inicio; p!=NULL ; p = p->proxima) {
        if (strcmp(p->item->nome, nome) == 0) {
            if (p == lista->inicio){
                lista->inicio = p->proxima;
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
    for (TipoCelula* p=lista->inicio; p!=NULL ; p = p->proxima) {
        printf("%s | %d | %s",
                p->item->nome,
                p->item->matricula,
                p->item->endereco);
    }
}

TipoListaDpl *libera(TipoListaDpl *lista) {
    for (TipoCelula* p=lista->inicio; p!=NULL ; p = p->proxima) {
        free(p->item->endereco);
        free(p->item->nome);
        free(p->item);
        if (p->anterior != NULL) {
            free(p->anterior);
        }
    }

    return NULL;
}

