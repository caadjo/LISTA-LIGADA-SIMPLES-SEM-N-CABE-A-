#include "LISTA 1.h"
#include <stdlib.h>

void inicializa_lista(Lista *ap_lista)
{
    *ap_lista = NULL;
}

void insere_fim(Lista *ap_lista, int valor)
{

    No *novo = (No *)malloc(sizeof(No));

    No **ap_recente = ap_lista;

    novo->valor = valor;
    novo->proximo = NULL;

    while (*ap_recente != NULL)
    {
        ap_recente = &((*ap_recente)->proximo);
    }

    *ap_recente = novo;
}

void insere_inicio(Lista *ap_lista, int valor)
{
    No *novo = (No *)malloc(sizeof(No));

    novo->valor = valor;
    novo->proximo = *ap_lista;
    *ap_lista = novo;
}

void imprime(Lista lista)
{

    printf("(");
    while (lista)
    {
        if (lista->proximo != NULL)
            printf("%d, ", lista->valor);
        else
            printf("%d", lista->valor);

        lista = lista->proximo;
    }
    printf(")");
}

int remove_fim(Lista *ap_lista)
{
    Lista *remover = ap_lista;

    int valor;

    while ((*remover)->proximo)
    {
        remover = &((*remover)->proximo); // testar ponteiro e sem ponteiro
    }

    valor = (*remover)->valor;

    free(*remover);

    *remover = NULL;

    return valor;
}

int remove_inicio(Lista *ap_lista)
{
    Lista *remover_primeiro = (*ap_lista)->proximo;

    int valor = (*ap_lista)->valor;

    free(*ap_lista);
    *ap_lista = remover_primeiro;

    return valor;
}

int busca(Lista lista, int valor)
{
    int contador = 0;
    while (lista->proximo)
    {
        if (valor == lista->valor)
        {
            return contador;
        }
        else
        {
            lista = lista->proximo;
            contador++;
        }
    }

    if (lista->proximo == NULL)
    {
        if (lista->valor == valor)
        {
            return contador;
        }
    }

    return -1;
}

int remove_ocorrencias(Lista *ap_lista, int valor)
{
    int contador = 0;
    if (!ap_lista)
    {
        return contador;
    }
    Lista *ap_recente = ap_lista;
    Lista ap_remove;

    while ((*ap_recente)->proximo)
    {
        if ((*ap_recente)->valor == valor)
        {
            contador++;
            ap_remove = *ap_recente;
            *ap_recente = (*ap_recente)->proximo;
            free(ap_remove);
        }
        else
        {
            ap_recente = &((*ap_recente)->proximo);
        }
    }
    if ((*ap_recente)->valor == valor)
    {
        remove_fim(ap_lista);
        contador++;
    }
    return contador;
}

void desaloca_lista(Lista *ap_lista)
{
    No *no_recente = *ap_lista;
    
  while(no_recente){

    No *no_prox = no_recente->proximo;

    free(no_recente);

    no_recente = no_prox;

  }
  *ap_lista = NULL;
}
