#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct no
{
    int dado;
    struct no *prox;
} no;


typedef struct lista
{
    no *inicio;
    no *fim;
} lista;


void create_lista(lista *l)
{
    l->inicio = NULL;
    l->fim =NULL;
}


int lista_vazia(lista *l)
{
    if(l->inicio ==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void insere(lista *l, int valor)
{

    no *novo=(no*)malloc(sizeof(no));
    novo->dado = valor;
    novo->prox = NULL;

    if(lista_vazia(l)==1)
    {
        l->fim = novo;
        l->inicio=novo;

    }
    else
    {
        novo->prox =l->inicio;
        l->inicio  =novo;

    }
}

int remove_fim(lista *l)
{
    int y;

    no *aux =(no*)malloc(sizeof(no));
    no *ant =(no*)malloc(sizeof(no));

    if(l->inicio == l->fim)
    {
        aux=l->fim;
        y=aux->dado;
        l->inicio = NULL;
        l->fim = NULL;
        free(aux);

    }
    else
    {

        ant =l->inicio;
        aux =l->fim;
        aux=l->fim->dado;

        while( ant->prox != l->fim)
        {
            ant=ant->prox;
        }
        l->fim = ant;
        ant->prox = NULL;
        free(aux);
    }
}

int remove_inicio(lista *l)
{

    int x;
    no *aux=(no*)malloc(sizeof(no));

    aux = l->inicio;

    if(lista_vazia(l)==1)
    {

        printf("lista esta vazia!!!");
        return 0;

    }
    else
    {

        if(l->inicio == l->fim)
        {
            x=aux->dado;
            l->fim=NULL;
            l->inicio=NULL;
            free(aux);
            return x;

        }
        else
        {
            x=aux->dado;
            l->inicio = aux->prox;
            aux->prox = NULL;
            free(aux);
            return x;

        }
    }
}

void insere_meio(lista *l, int valor)
{

    no *novo=(no*)malloc(sizeof(no));
    novo->dado=valor;
    novo->prox = NULL;

    no *aux=(no*)malloc(sizeof(no));
    no *ant=(no*)malloc(sizeof(no));

    aux=l->inicio;
    ant=l->inicio;

    while(aux->dado < valor) //procurar o valor
    {
        aux=aux->prox;

    }
// ----------valor encontrado
    while(ant->prox !=aux) //procurar o anterior
    {
        ant=ant->prox;
    }

    ant->prox = novo;
    novo->prox = aux;

}

void mostrar(lista *l)
{
        if(lista_vazia(l)==1)
        {
            printf("lista Vazia !!! \n");

        }
        else
        {
            no *aux=(no*)malloc(sizeof(no));
            aux=l->inicio;

            while(aux !=NULL)
            {
                printf(" | %d", aux->dado);
                aux=aux->prox;

            }

        }
}

void remove_meio(lista *l, int valor)
{

        int y;

        no *aux=(no*)malloc(sizeof(no));
        no *ant=(no*)malloc(sizeof(no));

        aux=l->inicio;
        ant=l->inicio;

        while(aux->dado !=valor)
        {
            aux=aux->prox; //incrementa o ponteiro
        }
//--------valor---------------
        if(aux ==l->inicio)  //encontrou o valor no inicio da lista
        {
            y=aux->dado;
            remove_inicio(l);

        }
        else if(aux == l->fim)
        {
            y=aux->dado;
            remove_fim(l);

        }
        else if(aux->dado == valor)
        {
            y=aux->dado;

            while(ant->prox != aux)
            {
                ant=ant->prox;  //movo o ponteiro do anterior
            }

            ant->prox = aux->prox;
            aux->prox = NULL;
            free(aux);
        }
}



void menu()
{
        lista *l=(lista*)malloc(sizeof(lista));
        create_lista(l);
        int opc;
        int num;
        int x;
        int y;

        do
        {
            system("cls");
            printf("0.Sair");
            printf("\n1.Cadastrar");
            printf("\n2.Mostrar");
            printf("\n3.Cadastrar no meio");
            printf("\n4.Remover ultimo");
            printf("\n5.Remove elemento de escolha");
            printf("\n Escolha uma opcao:");
            fflush(stdin);
            scanf("%d",&opc);

            switch(opc)
            {
            case 1:
                printf("\n |CADASTRAR|");
                printf("\n Entrada:");
                fflush(stdin);
                scanf("%d",&num);
                insere(l,num);
                break;
            case 2:
                printf("\n |MOSTRAR|");
                printf("\n");
                mostrar(l);
                getchar();
                getchar();
                break;
            case 3:
                printf("\n |CADASTRAR NO MEIO");
                printf("\n");
                printf("\n Entrada:");
                fflush(stdin);
                scanf("%d",&num);
                insere_meio(l,num);
                getchar();
                getchar();
                break;
            case 4:
                printf("\n |REMOVER ULTIMO");
                printf("\n");
                x = remove_fim(l);
                getchar();
                getchar();
                break;
            case 5:
                printf("\n |REMOVER QUALQUER LOCAL|");
                printf("\n");
                printf("\n Entrada :");
                fflush(stdin);
                scanf("%d",&num);
                remove_meio(l,num);
                break;
            default:
                break;

            }

        }while(opc != 0);
}


int main()
{
    menu();

    return 0;
}
