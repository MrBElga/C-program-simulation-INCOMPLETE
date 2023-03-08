#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "tad.h"


int main(){
    //define tamanho do prompt e o titulo do prompt
    system("MODE con cols=95 lines=35");
    system("title Simulacao de programa em C");
    textColor(BLACK,_DARKGRAY);
  
    telainicial();
  
    
    char op, arqName[30],flag='0';
    do{

        fflush(stdin);
        op=getche();
     
            if(op==65)
            {
                system("cls");
                box(2,2,12,94);
                linhaCol(6,4);
                printf("Nome Do Arquivo:");
                //lin1, col1, lin2, col2
                box(5,21,7,93);
                linhaCol(6,22);
                gets(arqName);

                while(strcmp(arqName,"")==0){
                    linhaCol(6,22); 
                    gets(arqName);
                }

                //deve ser implementadp em uma lista de listas        
                gera_arq_bin(arqName,&flag);

                while(flag == '0'){

                    linhaCol(6,22);
                    printf("                                                                       ");
                    linhaCol(6,22)  ;
                    textColor(BLACK,_DARKGRAY);

               
                    gets(arqName);
                    
                    while(strcmp(arqName,"")==0){
                        linhaCol(6,22);  
                        gets(arqName);
                    }
                    gera_arq_bin(arqName,&flag);
                }
                flag = '0';
               
            }    
            else if(op==66){
                system("cls");
                telainicial();
            }
            else if(op==67){  
                system("cls");  
                telaRam();
               

                
            }  
            else if(op==68){

                
            }            
        
    }while(op!=27);
 
    system("cls");
    printf("programa finalizado: ");

    return 0;
}