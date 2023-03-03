#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct TpListaC{
    char palav[50];
    struct TpLista *prox, *lin;

};
typedef struct TplistaC Lista;



struct TpPilhaRam
{
    int Endereco, valotI;
    char variavel;
    float valorF;
    struct TpPilhaRam *prox;
};
typedef struct TpPilhaRam Pilha;

struct TpListaPont
{
        

};
typedef struct TpListaPont ListaP;


