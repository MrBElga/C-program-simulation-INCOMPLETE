union termo
{
	float valor;
	char operador;
	char funcao[20];
};

struct listagen
{
	char terminal; //V O F
	union termo info;
	struct listagen *cabeca,*cauda;
};
typedef struct listagen ListaGen;

ListaGen *montaListaGen(ListCod *ini)
{
	Pilha *P;
	init(&P);
	ListaGen *L=NULL;
	ListCod *lc = ini;
	while(lc!=NULL)
	{
		if(L==NULL)
			L=atual=Cons(lc->token);
		else
		{
			if(strcmp(lc->token,"(")==0)
			{
				atual->cauda=Cons("0");
				atual=atual->cauda;
				push(&P,atual);
				lc=lc->prox;
				atual->cabeca=Cons(lc->token);
				atual=atual->cauda;
			}
			else
			if(strcmp(lc->token,")")==0)
			{
				pop(&P,&atual);
			}
			else
			{
				atual->cauda=Cons(lc->token);
				atual=atual->cauda;
			}	
		}
		lc=lc->prox;
	}
}
