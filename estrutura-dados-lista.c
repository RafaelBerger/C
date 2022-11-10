#include <stdlib.h>
#include <stdio.h>
#include "biblioteca.h"

int main()
{
    Lista *lista;
    lista = criaLista();

    int opcao, valor;

    do
    {
        printf("1 - inserir no inicio\n2 - imprimir\n3 - inserir no fim\n4 - remover item\n5 - sair\n");
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            printf("Digite um valor a ser inserido\n");
            scanf("%d", &valor);
            inserirInicio(lista, valor);
            break;
        case 2:
            imprimirLista(lista);
            break;
        case 3:
            printf("Digite um valor a ser inserido\n");
            scanf("%d", &valor);
            inserirFim(lista, valor);
            break;
        case 4:
            printf("Digite um valor a ser removido\n");
            scanf("%d", &valor);
            remover(lista, valor);
            break;
        case 5:
            printf("Finalizando...\n");
            break;
        default:
            printf("Opcao invalida");
        }
    } while(opcao != 5);
        
    return 0;
}
