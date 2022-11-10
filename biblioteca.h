#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <stdio.h>
#include <stdlib.h>


//estruturas

typedef struct no{
    int num;
    struct no *proximo;
}No;

No* criaNo(int valor){
    No *novo = malloc(sizeof(No));
    novo->num = valor;
    novo->proximo = NULL;
    return novo;
}

typedef struct
{
    No *inicio;
    int tam;
} Lista;

Lista* criaLista(){
    Lista *lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->tam = 0;
    return lista;
}


//Funções de imprimir


void imprimirLista(Lista *lista)
{
    No *inicio = lista->inicio;
    printf("Tamanho da lista: %d\n", lista->tam);
    while(inicio != NULL)
    {
        printf("%d ", inicio->num);
        inicio = inicio->proximo;
    }
    printf("\n\n");
}

//inserir


void inserirInicio(Lista *lista, int numero)
{
    No *novo = criaNo(numero);

    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tam++;
    printf("\nNumero inserido: %d\n", novo->num);
}

void inserirFim(Lista *lista, int numero)
{
    No *no, *novo = criaNo(numero);

    if(lista->inicio == NULL)
    {
        lista->inicio = novo;
    }
    else
    {
        no = lista->inicio;
        while(no->proximo != NULL)
        {
            no = no->proximo;
        }
        no->proximo = novo;
    }
    lista->tam++;
}

//remover


void remover(Lista *lista, int numero)
{
    No *inicio = lista->inicio;
    No *noARemover = NULL;


    if(lista->inicio != NULL && lista->inicio->num == numero)
    {
        noARemover = lista->inicio;
        lista->inicio = noARemover->proximo;
    }
    else
    {
        while(inicio != NULL && inicio->proximo->num != numero)
        {
            inicio = inicio->proximo;
        }
        if(inicio != NULL){
            noARemover = inicio->proximo;
            inicio->proximo = noARemover->proximo;
        }
    }
    if(noARemover != NULL){
        free(noARemover);
        lista->tam--;
    }
  
}

#endif

