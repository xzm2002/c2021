#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,m;

	scanf("%d",&n);
	if(n==2)  printf("yes");
	else if(n>2)
	{
		for(i=2;i<n;i++)
		{
			if(n%i==0) {m=1; break;}
		}
		if(m==1) printf("no");
		else printf("yes");
	}
	else printf("error");
return 0;
}
