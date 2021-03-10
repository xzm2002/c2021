#include<stdio.h>

int main()
{
    for(float x=1;;x++)
    { if(x==x*11/28+5+x/2+4)
       { printf("%d",(int)x-4);
    break;}
    }
    return 0;
}
