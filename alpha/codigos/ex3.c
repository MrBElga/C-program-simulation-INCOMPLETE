#include<stdio.h>

int faz_uma_repeticao(int X, int n)
{
    int i, result;
    i=0;
    result=1;
    while (i<n)
    {
        result=result * X;
        i=i+1;
    }
    return result;
}
int main()
{
    int s;
    s =faz_uma_repeticao(2,4);
    printf("Resultado = %d\n",s);
}
