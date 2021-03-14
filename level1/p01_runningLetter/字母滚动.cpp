#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<unistd.h>
#define H 15
#define W 20
int c[H][W] ={0};
int i,j,k;

void gotoxy(int x,int y)  
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

void HideCursor()

{

CONSOLE_CURSOR_INFO cursor_info = {1, 0};

SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);

}

void ain()
{
	
	for (i=0;i<H;i++)
	{
		c[i][0] = -1;
		c[i][W-1] =- 1;
	}
	for (j=0;j<W;j++)
	{
		c[0][j] =- 1;
		c[H-1][j] = -1;
	}
	for(int z=1;z<W-1;z++)
	{
		c[1][1]=1;
	}
}
void m()
{
	
	for (i=0;i<H;i++)
	{
		for (j=0;j<W;j++)
		{
			if (c[i][j]==0)
				printf(" ");   
			else if (c[i][j]==-1)
				printf("#");
			else printf("A");
		}
		printf("\n");
	}
 }

int main()
{
	HideCursor(); 
	ain();
	m();
		for(int u=0;;)	
			{
				if(u==0)
				{
				for(int z=1;z<18;z++)
				{
				sleep(1);
				gotoxy(0,0);
				c[1][z]=0;
				c[1][z+1]=1;
				m();
				}
			u=1;
			}
		if(u==1)
		{
		for(int h=18;h>1;h--)
			{
			sleep(1);
			system("cls");
			c[1][h]=0;
			c[1][h-1]=1;
				m();
		}
		u=0;
	}		
}
return 0;	
}
