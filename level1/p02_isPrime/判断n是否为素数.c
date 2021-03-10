#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,m;
	int a[1000];
	scanf("%d",&n);
	if(n==2)  printf("yes");
	else if(n>2)
	{
		for(i=2;i<n;i++)
		{
			if(n%i==0) {a[i]=1; break;}
		}
		if(a[i]==1) printf("no");
		else printf("yes");
	}
	else printf("error");
return 0;
}
