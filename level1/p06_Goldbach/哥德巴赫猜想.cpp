#include<stdio.h>
#include<math.h>
#include<string.h>
int b[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int sushu(int n)
{
	for(int i=0;i<=24;i++)
	{
		if(n==b[i]) return 1;
	}
	return 0;
}

int main()
{
	int n,i,m;
	int a[1000];
	for(int j=4;j<=100;j=j+2)
	{
		m=j/2;
		n=j/2;
		while(sushu(m)!=1 || sushu(n)!=1)
		   {
		   
			m++;
			n--;
		}
			printf("%d=%d+%d\n",j,m,n);
	}
		
	
return 0;	
}
