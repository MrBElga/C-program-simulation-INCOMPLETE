void calcula(int x, int y, int *z)
{
    *z=x + y;
}

int main()
{ 
    int a,b,c;
    
    a=5;
    b=8;
    c=3;

    calcula(a,b,&c);
    printf("%d %d %d\n",a,b,c);
    calcula(7,a+b+c,&a);
    printf("%s %d %d\n","7",a+b+c,a);
    calcula(a*b,a/b,&c);
    printf("%d %d %d\n",a*b,a/b,c);
    calcula(b,b+b,&a);
    printf("%d %d %d\n",a,b,c);
}