#include<iostream>
#include<cstring>
using namespace std;	
char b[1000];
char c[1000];
int jiami(string a)
{

	int len;
	len=a.length();
	for(int i=0;i<=len;i++)
	{
		b[i]=a[i]-24;
	}
	
		
}
int jiemi(string b)
{
	int len;
	len=b.length();
	for(int i=0;i<=len;i++)
	{
		c[i]=b[i]+24;
	}
}

int main()

{
	string a;
	cin>>a;
	jiami(a);
	cout<<b<<endl;
	jiemi(b);
	cout<<c<<endl;
	
	
	
return 0;
}
