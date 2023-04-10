#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "tad.h"

int main()
{
    // define tamanho do prompt e o titulo do prompt
    
    system("MODE con cols=95 lines=35");
    system("title Simulacao de programa em C");
    textColor(BLACK, _DARKGRAY);

    telainicial();

    char op, arqName[30], flag = '0';
    int i = 3,j = 3,contlin=0,cont=0;
    Coluna *Col;
    Linha *Lin, *aux;

    initListaC(&Col);
    initListaL(&Lin);
    initListaL(&aux);
    do
    {
        fflush(stdin);
        op = getche();
		
        if (op == 65)
        {
            system("cls");
            box(2, 2, 12, 94);
            linhaCol(6, 4);
            printf("Nome Do Arquivo:");
            // lin1, col1, lin2, col2
            box(5, 21, 7, 93);
            linhaCol(6, 22);
            fflush(stdin);
            gets(arqName);

            while (strcmp(arqName, "") == 0)
            {
                linhaCol(6, 22);
                fflush(stdin);
                gets(arqName);
            }

            // deve ser implementadp em uma lista de listas
            while (flag != '1')
            {
                FILE *arq = fopen(arqName, "r");
                if(arq)
                {
                    flag = '1';
                }
                else
                {
                    linhaCol(8, 25);
                    textColor(RED, _DARKGRAY);
                    printf("ERRO: verifique se o arquivo existe ou se eh um .C");
                    linhaCol(6, 22);
                    printf("                                                                       ");
                    linhaCol(6, 22);
                    textColor(BLACK, _DARKGRAY);
                    
                    fflush(stdin);
                    gets(arqName);

                    while (strcmp(arqName, "") == 0)
		            {
		                linhaCol(6, 22);
		                fflush(stdin);
		                gets(arqName);
		            }
                }
                fclose(arq);
            }
            if(Lin!=NULL)
            	excluirLista(&Lin);
            gerarLista(&Lin,&Col, arqName);
          
           	system("cls");
           	telainicial();
            aux = Lin;
         
           	i = localizaMain(Lin)+3;
           	exibeEnter(Lin,i);
        	flag = '0';
           
            
            while(aux->prox!=NULL)
            {
            	
            	aux=aux->prox;
            	
			}
			contlin = aux->linha + 2;
			aux = Lin;
			cont = i;
		
        }
        else if (op == 66)
        {
            system("cls");
            telainicial();
        }
        else if (op == 67)
        {
            system("cls");
            telaRam();
        }
        else if (op == 68)
        {
        }
        else if(op == 13 && Lin != NULL &&  contlin >= cont)
        {
        
				
        	cont++;
        	printf("\n\n\n\n%s",aux->inicio->token);
        	printf("%d",cont);
        	if(strcmp(aux->inicio->token,"vazia")!=0)
            {
            	//printf("achei><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
            	printf("\n%s",aux->inicio->palav);
               	contlin = localizaFuncao(aux,aux->inicio->palav);
               	printf("\n\n\n%d",contlin);
                exibeEnter(Lin, contlin);
            }
            else	
            	exibeEnter(Lin, cont);
        	//aux = aux->prox;
        	
		}
        else if(op == 13 && Lin != NULL && cont >= contlin)
        {

        }

    } while (op != 27);
    

    system("cls");
    printf("programa finalizado: ");

    return 0;
}
