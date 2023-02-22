#include<stdio.h>
#include<stdlib.h>
/*Autor: Ruben Alves do Nascimento
  Contato: rubenanapu@hotmail.com      
*/
main(){
      
       char c;
       printf("\nDigite QUALQUER TECLA para saber o codigo na ASCII TABLE ou ESC para sair:\n");
       do{
       c=getch();       //Armazena o caractere pressionado na variável c
       printf("O valor na tabela ASCCI %c %i\n",130,c);
       }while(c!=27);  //27 é o caractere ESC na tabela ASCII
      
system("pause");      
}