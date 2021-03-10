#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    int a,b,c;
    for(int i=100;i<1000;i++)
    {
       	a=(i%100)%10;
        b=(i%100)/10;
        c=i/100;
        n=pow(c,3)+pow(b,3)+pow(a,3);
        if(i==n) printf("%d\n",i);
       
    }
    return 0;
}
