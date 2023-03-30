#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No_aux
{
    int valor;
    struct No_aux *proximo;
} No;
typedef No *Lista;

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

    (*remover)->valor = NULL;

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

int main()
{
   int x, conta, posicao;
  char comando[300];
  Lista l;
  inicializa_lista(&l);
  while(scanf("%s", comando) == 1) {
    if (strcmp(comando, "insere_inicio") == 0) {
      if(scanf("%d", &x) != 1) return 1;
      insere_inicio(&l, x);
      printf("Inserido %d no inicio.\n", x);
    }else if (strcmp(comando, "insere_fim") == 0) {
      if(scanf("%d", &x) != 1) return 1;
      insere_fim(&l, x);
      printf("Inserido %d no fim.\n", x);
    }else if (strcmp(comando, "remove_inicio") == 0) {
      x = remove_inicio(&l);
      printf("Removido %d do inicio.\n", x);      
    }else if (strcmp(comando, "remove_fim") == 0) {
      x = remove_fim(&l);
      printf("Removido %d do fim.\n", x);      
    }else if (strcmp(comando, "remove_ocorrencias") == 0) {
      if(scanf("%d", &x) != 1) return 1;
      conta = remove_ocorrencias(&l, x);
      printf("Removidas %d ocorrencias de %d.\n", conta, x);      
    }else if (strcmp(comando, "busca") == 0) {
      if(scanf("%d", &x) != 1) return 1;
      posicao = busca(l, x);
      if (posicao == -1) {
	printf("Valor %d nao encontrado na lista.\n", x);
      }else {
	printf("Valor %d encontrado na posicao %d.\n", x, posicao);            
      }
    }else if (strcmp(comando, "imprime") == 0) {
      imprime(l);
    }else {
      printf("Comando invalido.\n");
      return 2;
    }
  }
  desaloca_lista(&l);
  return 0;
}