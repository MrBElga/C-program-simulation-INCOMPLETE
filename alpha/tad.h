
// Tela
void linhaCol(int lin, int col);
void box(int lin1, int col1, int lin2, int col2);
void textColor(int letras, int fundo);

// COR DA LETRA
enum
{
    BLACK,        // 0
    BLUE,         // 1
    GREEN,        // 2
    CYAN,         // 3
    RED,          // 4
    MAGENTA,      // 5
    BROWN,        // 6
    LIGHTGRAY,    // 7
    DARKGRAY,     // 8
    LIGHTBLUE,    // 9
    LIGHTGREEN,   // 10
    LIGHTCYAN,    // 11
    LIGHTRED,     // 12
    LIGHTMAGENTA, // 13
    YELLOW,       // 14
    WHITE         // 15

};

// COR DO FUNDO
enum
{
    _BLACK = 0,          // 0
    _BLUE = 16,          // 1
    _GREEN = 32,         // 2
    _CYAN = 48,          // 3
    _RED = 64,           // 4
    _MAGENTA = 80,       // 5
    _BROWN = 96,         // 6
    _LIGHTGRAY = 112,    // 7
    _DARKGRAY = 128,     // 8
    _LIGHTBLUE = 144,    // 9
    _LIGHTGREEN = 160,   // 10
    _LIGHTCYAN = 176,    // 11
    _LIGHTRED = 192,     // 12
    _LIGHTMAGENTA = 208, // 13
    _YELLOW = 224,       // 14
    _WHITE = 240         // 15
};

void textColor(int letra, int fundo)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letra + fundo);
}

void linhaCol(int lin, int col)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){col - 1, lin - 1}); // coorddenada na tela

    // funcao para deixar o cursor invisivel
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void box(int lin1, int col1, int lin2, int col2)
{
    int i = 0, j = 0;

    // setar tamanho da tela e titulo do CMD

    for (i = col1; i <= col2; i++)
    { // linhas
        linhaCol(lin1, i);
        printf("%c", 196);
        linhaCol(lin2, i);
        printf("%c", 196);
    }

    for (i = lin1; i <= lin2; i++)
    { // colunas

        linhaCol(i, col1);
        printf("%c", 179);
        linhaCol(i, col2);
        printf("%c", 179);
    }

    for (i = lin1 + 1; i < lin2; i++)
    { // percorre caixa
        for (j = col1 + 1; j < col2; j++)
        {
            linhaCol(i, j);
            printf(" ");
        }
    }

    // cantos
    linhaCol(lin1, col1);
    printf("%c", 218);
    linhaCol(lin1, col2);
    printf("%c", 191);
    linhaCol(lin2, col1);
    printf("%c", 192);
    linhaCol(lin2, col2);
    printf("%c", 217);
}

void telainicial()
{
    // lin1, col1, lin2, col2
    box(2, 2, 33, 94);
    linhaCol(34, 4);
    textColor(BLUE, _DARKGRAY);
    printf("F7 ");
    textColor(BLACK, _DARKGRAY);
    printf("- ABRIR\t");
    textColor(BLUE, _DARKGRAY);
    printf("F8 ");
    textColor(BLACK, _DARKGRAY);
    printf("- EXECUTAR\t");
    textColor(BLUE, _DARKGRAY);
    printf("F9 ");
    textColor(BLACK, _DARKGRAY);
    printf("- MEMORIA RAM\t");
    textColor(BLUE, _DARKGRAY);
    printf("F10 ");
    textColor(BLACK, _DARKGRAY);
    printf("- TELA\t");
    textColor(BLUE, _DARKGRAY);
    printf("ESC ");
    textColor(BLACK, _DARKGRAY);
    printf("- SAIR\t");
}

// arquivo X -> arquivo binario

void imprime(char arqName[])
{
    char a[100], arqNameB[50];
    int col1 = 3, i = 3;
    strcpy(arqNameB, arqName);
    strcat(arqNameB, ".dat");

    telainicial();

    linhaCol(2, 3);
    printf("%c%s%c", 179, arqName, 179);
    FILE *arqBin = fopen(arqNameB, "rb");

    fread(&a, sizeof(char), 100, arqBin);
    while (!feof(arqBin) && i != 33)
    {
        linhaCol(i, col1);
        printf("%s\n", a);
        fread(&a, sizeof(char), 100, arqBin);
        i++;
        // Sleep(500);
    }
}

void telaRam()
{
    int i = 0, j = 0;
    box(2, 2, 33, 94);
    linhaCol(4, 10),
        printf("RAM");
    // lin1, col1, lin2, col2
    box(6, 3, 32, 20);
    for (j = 6; j < 32; j = j + 2)
    {
        for (i = 4; i < 20; i++)
        {

            if (i == 4 && j > 6)
            {
                linhaCol(j, i - 1);
                printf("%c", 195);
            }

            linhaCol(j, i);
            printf("%c", 196);
        }
        if (j > 6)
        {
            linhaCol(j, i);
            printf("%c", 180);
        }
        // 197 kreuz
    }

    // duplicar coluna para direita, tabela de variaveis e valores(int, float e endereço)
}
// estruturas
struct TpListaC
{
    char palav[50];
    struct TpListaC *proxC, *antC;
};
typedef struct TpListaC Coluna;

struct Tplinha
{
    struct TpListaC *inicio;
    struct Tplinha *prox, *ant;
};
typedef struct Tplinha Linha;

// iniciar lista
void initListaC(Coluna **C)
{
    *C = NULL;
}	

void initListaL(Linha **L)
{
    *L = NULL;
}

// vazia

int isEmpetyC(Coluna *inicio)
{
    return inicio == NULL;
}

int isEmpetyL(Linha *inicio)
{
    return inicio == NULL;
}

// nova caixa




void listaCol(Coluna **col, char aux[90])
{
		Coluna *auxC, *novo = (Coluna *)malloc(sizeof(Coluna));
			    novo->proxC = novo->antC = NULL;
			    strcpy(novo->palav, aux);
			    if(*col == NULL)
				{
			    	*col = novo;  
			    	//(*lin)->inicio = *col;
					         
			    }
			    else
			   	{
			   	 	auxC = *col;
			        while(auxC->proxC != NULL)
			            auxC = auxC->proxC;
			             
			     	auxC->proxC = novo;
			    	novo->antC = auxC;
    			}
    
          
}

// gerar lista de lista com o codigo
void gerarLista(Linha **lin,Coluna **col,char NomeArq[])
{
    int i = 0,j = 0;
    char auxs[90]={}, aux[90]={};

    Linha *nova,*auxL;
    
    FILE *arq = fopen(NomeArq, "r");

    fgets(auxs,90,arq);
    while(!feof(arq))
    {
        Linha *nova = (Linha *)malloc(sizeof(Linha));
        nova->prox = nova->ant = NULL;
        nova->inicio = NULL;

        if(*lin == NULL)
        {
            *lin = nova;   
           
        }
        else
        {
            auxL = *lin;
            while(auxL->prox!=NULL)
                auxL = auxL->prox;
            auxL->prox = nova;;
            nova->ant = auxL;
        }
      
		while(i != strlen(auxs))
	    {
            if(auxs[i] >= 33 && auxs[i] <= 126)
            {
                aux[j] = auxs[i];
                j++;
            }
			else
			{
			 	listaCol(&nova->inicio,aux);
				for(;j>=0;j--)
                	aux[j] = '\0';
               	j=0;
            }
			 
			
            i++;
     	}
                   
        for(;j>=0;j--)
            aux[j] = '\0';
        j=0;
        i=0;
  
        fgets(auxs,90,arq);
    }
    fclose(arq);
}

void exibeL(Linha *L)
{
    int  i = 3, j = 3; 
    Coluna *aux;
    while(L != NULL)
    {  
        
        aux = L->inicio;
       
        linhaCol(i, j);
        while(aux != NULL)
        {  
            printf("%s ",aux->palav);
           aux = aux->proxC;
        }
       	i++;
        L = L->prox;
    }
}

void exibeEnter(Linha *L,int pos)
{
    int  i = 3, j = 3 , lin, col; 
    Coluna *aux;
    
    
	telainicial();
    
 
    while(L != NULL)
    {  
        aux = L->inicio;
        if(i==pos)
		{
        	textColor(WHITE, _CYAN);
		    for (col = j; col < 94; col++)
	    	{
	            linhaCol(i,col);
		        printf(" ");
	        }
		}
        else
        	textColor(BLACK, _DARKGRAY);
        	
        while(aux != NULL)
        {  
           linhaCol(i,j);
	       printf("%s",aux->palav);
	          j = j + strlen(aux->palav)+1;
           aux = aux->proxC;
        
        }
       	i++;
       	j=3;
        L = L->prox;
    }
}
