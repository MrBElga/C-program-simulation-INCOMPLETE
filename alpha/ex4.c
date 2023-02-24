#include<stdio.h>
#include<math.h>

float juros_composto(float P, float i, int n)
{
    float M;
    M = P*pow(1 + i/100,n);
    return M;
}
int main()
{
    float res = juros_composto(2000, 1.5, 10);
    printf("Resultado = %f\n",res);
} 