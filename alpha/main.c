#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "tad.h"
#include "tela.h"

int main(){
  
    textColor(BLACK,_DARKGRAY);
    //lin1, col1, lin2, col2
    box(2,2,33,94);

    char op;
    do{

        fflush(stdin);
        op=getche();
     
            if(op==65)
            {
                gera_arq_bin();
                imprime();
            }
            else if(op==66){
                system("cls");
                box(2,2,33,94);
            }
            else if(op==67){

                
            }  
            else if(op==68){

                
            }            
        
    }while(op!=27);
 
    system("cls");
    printf("programa finalizado: ");

    return 0;
}