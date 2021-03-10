#include<stdio.h>
#include<math.h>
#include<time.h>
int main()
{
	int n,i,m;
	int a[1000];
	clock_t t1,t2;
	t1=clock();
	printf("%d\n",2);
	for(int j=3;j<=1000;j++)
	{
		for(i=2;i<j;i++)
		{
			if(j%i==0) {a[j]=1; break;}
		}
		if(a[j]!=1) printf("%d\n",j);
	}
	t2=clock();
	printf("该程序运行的时间为%d毫秒\n",t2-t1);
return 0;
}
