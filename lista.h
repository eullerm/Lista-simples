#ifndef LISTA_LISTA_H
#define LISTA_LISTA_H

typedef struct lista{
    int info;
    struct lista *prox;
}TLista;

//Trecho do primeiro exercicio
TLista *insere_fim(TLista *li, int i);

//Trecho do segundo exercicio.
TLista *insere_ordenado(TLista *li, int i);

//Trecho do terceiro exercicio.
TLista *exclui(TLista *li, int i);

//Trecho do quarto exercicio.
TLista *altera(TLista *li, int vantigo, int vnovo);

//Inicia a lista com valor NULL.
TLista *inicializa();

#endif