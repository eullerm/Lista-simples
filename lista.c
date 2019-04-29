#include "lista.h"

#include <stdio.h>
#include <malloc.h>


//Trecho do primeiro exercicio
TLista *insere_fim(TLista *li, int i){

    //Aloca o espaço para o novo elemento.
    TLista *novo=(TLista*) malloc(sizeof(TLista));
    //Coloca a informação
    novo->info=i;
    novo->prox=NULL;

    //Verifica se a lista está vazia.
    if(li==NULL) li=novo;
    else {
        TLista *aux = li;
        //Percorre até achar o ultimo valor
        while (aux->prox) aux = aux->prox;
        aux->prox = novo;
    }

    return li;
}

//Trecho do segundo exercicio.
TLista *insere_ordenado(TLista *li, int i){

    //Aloca um espaço para uma nova informação
    TLista *novo=(TLista*) malloc(sizeof(TLista));
    //Atribui a informção
    novo->info=i;
    novo->prox=NULL;
    //Verifica se a lista está vazia
    if(li==NULL) li=novo;
        //Checa se o primeiro elemento é maior que o novo
        //Se for, o novo apontara para o li(antigo começo da lista) se tornara o novo começo.
    else if(li->info>i){
        novo->prox=li;
        return novo;
    }
    else{
        TLista *a=li;
        TLista *b=NULL;
        //Percorre até achar um elemento maior e coloca a informação antes dele
        //Ou percorre até achar NULL, sendo assim coloca na ultima posição
        while(a!=NULL && a->info<novo->info){
            b=a;
            a=a->prox;
        }
        b->prox=novo;
        novo->prox=a;
    }

    return li;
}

//Trecho do terceiro exercicio.
TLista *exclui(TLista *li, int i){
    //Chega se a lista está vazia.
    if(li==NULL){
        printf("Lista vazia!\n");
        return NULL;
    }
    else{
        //Checa se o primeiro elemento da lista é o valor que será removido.
        //Caso seja faz do segundo elemento o primeiro.
        if(li->info==i){
            TLista *tmp = li;
            li=li->prox;
            tmp->prox=NULL;
            free(tmp);
        }
        else {
            TLista *a = li;
            TLista *b = NULL;
            //Percorre até achar NULL ou o elemento que sera removido.
            while (a != NULL && a->info != i) {
                b = a;
                a = a->prox;
            }
            //Checa se achou o elemento.
            if (a == NULL) {
                printf("Valor nao está na lista.\n");
            }
            else {
                b->prox = a->prox;
                a->prox=NULL;
                free(a);
            }
        }
    }

    return li;
}

//Trecho do quarto exercicio.
TLista *altera(TLista *li, int vantigo, int vnovo){
    //Checa se a lista está vazia.
    if(li==NULL){
        return NULL ;
    }
    else{
        TLista *a=li;
        //Percorre até encontrar o NULL ou o valor que devera ser trocado.
        while(a!=NULL && a->info!=vantigo){
            a=a->prox;
        }
        //Checa se achou o valor que devera ser trocado.
        if(a==NULL){
            printf("Valor nao está na lista.\n");
        }
        else {
            a->info = vnovo;
        }
    }
    return li;

}

//Inicia a lista com valor NULL.
TLista *inicializa(){
    return NULL;
}