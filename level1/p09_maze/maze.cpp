#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

#define high 25
#define weight 50

int x,y;
int i,j;

int maze[high][weight]={0}; 


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

void start()
{
	
	for	(i=0;i<high;i++)
	{
		maze[i][0]=-1;
		maze[i][weight-1]=-1;
	}
	for(j=0;j<weight;j++)
	{
		maze[0][j]=-1;
		maze[high-1][j]=-1;
	}
	for(int z=0;z<=750;z++)
	maze[rand()%26][rand()%51]=-1;
	
	x=1;y=0;
	maze[y][x]=1;
	maze[24][48]=0;
	
	
}


void show()
{
	gotoxy(0,0);
	for(i=0;i<high;i++)
	{
		for(j=0;j<weight;j++)
		{
			if(maze[i][j]==0) printf(" ");
			else if(maze[i][j]==-1) printf("#");
			else if(maze[i][j]==1) printf("@");
		}
		printf("\n");
	}
	for(i=0;i<high;i++)
	{
		for(j=0;j<weight;j++)
		{
			maze[y][x]=0;	
		}

	}
 } 
 
void datawithinput()
{
	char input;
	if(kbhit())
	{
		input=getch();
		if(input=='w') y--;
		else if(input=='s') y++;
		else if(input=='d') x++;
		else if(input=='a') x--;
	}
	
}

void datawithoutinput()
{
	
	HideCursor();
	for(i=0;i<high;i++)
	{
		for(j=0;j<weight;j++)
		{
			maze[y][x]=1;	
		}
	}
	if(y==24 && x==48) 
	{
	printf("you are successful\n"); 
	system("pause");
	exit(0);
	}
 } 




int main()
{
	start();
	show();
	while(1)
	{
		datawithinput();
		datawithoutinput();
		show();		
	}
	return 0;
 } 
