#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Tela
void linhaCol(int lin, int col);
void box(int lin1, int col1, int lin2, int col2);
void textColor(int letras, int fundo);

  //COR DA LETRA
  enum{BLACK,                 //0
       BLUE,                  //1
       GREEN,                 //2
       CYAN,                  //3
       RED,                   //4
       MAGENTA,               //5
       BROWN,                 //6
       LIGHTGRAY,             //7
       DARKGRAY,              //8
       LIGHTBLUE,             //9
       LIGHTGREEN,            //10
       LIGHTCYAN,             //11
       LIGHTRED,              //12
       LIGHTMAGENTA,          //13
       YELLOW,                //14
       WHITE                  //15
       
       };  

  //COR DO FUNDO
  enum{_BLACK=0,                 //0
       _BLUE=16,                  //1
       _GREEN=32,                 //2
       _CYAN=48,                  //3
       _RED=64,                   //4
       _MAGENTA=80,               //5
       _BROWN=96,                 //6
       _LIGHTGRAY=112,             //7
       _DARKGRAY=128,              //8
       _LIGHTBLUE=144,             //9
       _LIGHTGREEN=160,            //10
       _LIGHTCYAN=176,             //11
       _LIGHTRED=192,              //12
       _LIGHTMAGENTA=208,          //13
       _YELLOW=224,                //14
       _WHITE=240                  //15       
       };  
       
void textColor(int letra, int fundo){
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letra + fundo);
}
     
void linhaCol(int lin, int col){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){col-1,lin-1});// coorddenada na tela
     
     //funcao para deixar o cursor invisivel
     HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_CURSOR_INFO info;
     info.dwSize = 100;
     info.bVisible = FALSE;
     SetConsoleCursorInfo(consoleHandle, &info);
}

void box(int lin1, int col1, int lin2, int col2){
    int i=0, j=0;

    //setar tamanho da tela e titulo do CMD
    

    for(i=col1;i<=col2;i++){ //linhas 
        linhaCol(lin1,i);
        printf("%c",196);
        linhaCol(lin2,i);
        printf("%c",196);
  
    }

    for(i=lin1;i<=lin2;i++){ //colunas
        
        linhaCol(i,col1);
        printf("%c",179);
        linhaCol(i,col2);
        printf("%c",179);
    }

    for(i=lin1+1;i<lin2;i++){//percorre caixa
        for(j=col1+1;j<col2;j++){
            linhaCol(i,j);
            printf(" ");
        }
    }
    
    //cantos
    linhaCol(lin1,col1);
    printf("%c",218);
    linhaCol(lin1,col2);
    printf("%c",191);
    linhaCol(lin2,col1);
    printf("%c",192);
    linhaCol(lin2,col2);
    printf("%c",217);
}

void telainicial(){
  //lin1, col1, lin2, col2
    box(2,2,33,94);
    linhaCol(34,4);
    textColor(BLUE,_DARKGRAY);
    printf("F7 ");  textColor(BLACK,_DARKGRAY);printf("- ABRIR\t");
    textColor(BLUE,_DARKGRAY);
    printf("F8 ");  textColor(BLACK,_DARKGRAY);printf("- EXECUTAR\t"); 
    textColor(BLUE,_DARKGRAY);
    printf("F9 ");  textColor(BLACK,_DARKGRAY);printf("- MEMORIA RAM\t");
    textColor(BLUE,_DARKGRAY);
    printf("F10 "); textColor(BLACK,_DARKGRAY);printf("- TELA\t"); 
    textColor(BLUE,_DARKGRAY);
    printf("ESC "); textColor(BLACK,_DARKGRAY);printf("- SAIR\t"); 
}

//arquivo X -> arquivo binario

void imprime(char arqName[])
{
    char a[100],arqNameB[50];
    int col1=3,i=3;
    strcpy(arqNameB,arqName);
    strcat(arqNameB,".dat");
   
    telainicial();

    linhaCol(2,3);
    printf("%c%s%c",179,arqName,179);
	FILE *arqBin = fopen(arqNameB,"rb");
    
    fread(&a,sizeof(char),100,arqBin);
    while (!feof(arqBin) && i!=33)
	{	   
        linhaCol(i,col1);
    	printf("%s\n",a);
        fread(&a,sizeof(char),100,arqBin);
        i++;
       // Sleep(500);
       
    }  
}

void telaRam(){
    int i=0,j=0;
    box(2,2,33,94);
    linhaCol(4,10),
    printf("RAM");
    //lin1, col1, lin2, col2
    box(6,3,32,20);
    for(j=6; j<32; j=j+2){   
        for(i=4; i<20; i++){   

            if(i==4 && j>6){
                linhaCol(j,i-1);
                printf("%c",195);
            }

            linhaCol(j,i);
            printf("%c",196);   
        }
        if(j>6){
            linhaCol(j,i);
            printf("%c",180);
        }
        //197 kreuz 
    }

    //duplicar coluna para direita, tabela de variaveis e valores(int, float e endereço)
}

void gera_arq_bin(char arqName[],char *flag)
{ 
    char a[100],arqNameB[50];

    strcpy(arqNameB,arqName);
    strcat(arqNameB,".dat");
    FILE *arq = fopen(arqName,"r");
    
    if(arq)
    {
    	FILE *arqBin = fopen(arqNameB,"wb");

        fgets(a,100,arq);
        while(!feof(arq))
        {
            fwrite(a,1,sizeof(a),arqBin);
            fgets(a,100,arq);
        }
        fclose(arq);
        fclose(arqBin);
        system("cls");
        imprime(arqName);
        *flag = '1';
    }
    else{
        linhaCol(8,25);
        textColor(RED,_DARKGRAY);
        printf("ERRO: verifique se o arquivo existe ou se eh um .C");
        fclose(arq);
    }  
    
}
