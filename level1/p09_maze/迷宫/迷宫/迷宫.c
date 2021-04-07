#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#define M 25
int map[M ][M ] = { 0 };
int num;
int i = 0,j = 0;
int now_x=1, now_y=1;


void gotoxy(int x, int y) 
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

void create(int x_start, int y_start)
{
	int x, y;
	int rand_position, flag = 0;
	x = x_start;
	y = y_start;
	while (1)
	{
		flag = 0;
		if ((x_start > 3 && map[x_start - 2][y_start] == 1) || (x_start<M-3 && map[x_start + 2][y_start] == 1) || (y_start > 3 && map[x][y_start - 2] == 1) || (y_start < M - 3 && map[x][y_start + 2] == 1))
		{
			flag = 1;
		}
		if (flag == 0)
		{
			return;
		}
		else 
		{
			map[x_start][y_start] = 5;
			x = x_start;
			y = y_start;
			while (1)
			{
				rand_position = rand() % 4;

				if (rand_position == 0  && map[x_start + 2][y_start] == 1)
				{
					x_start = x_start + 2;
				}
				else if (rand_position == 1 && map[x_start - 2][y_start] == 1)
				{
					x_start = x_start - 2;
				}
				else if (rand_position == 2 && map[x_start][y_start + 2] == 1)
				{
					y_start = y_start + 2;
				}
				else if (rand_position == 3&& map[x_start][y_start - 2] == 1)
				{
					y_start = y_start - 2;
				}

				map[(x + x_start) / 2][(y + y_start) / 2] = 5;
				map[x_start][y_start] = 5;
				create(x_start, y_start);
				break;
			}
		}
	}
	
}

void start()
{
	int i, j;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
			{
				map[i][j] = 0;
			}
	}
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
		{
			 if (i != 0 && j != 0 && i != M - 1 && j != M - 1)
			{
				if (i % 2 == 1 && j % 2 == 1)
				{
					map[i][j] = 1;
				}
			}
		}
	}
	create(1, 1);
	map[1][1] = 3;
	map[M - 2][M - 2] = 4;
}




void print()
{
	
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				printf("¡ö");
			}
			else if (map[i][j] == 1)
			{
				printf("  ");
			}
			else if (map[i][j] == 3)
			{
				printf("¡ğ");
			}	
			else if (map[i][j] == 4)
			{
				printf("¡ó");
			}	
		}	
		printf("\n");
	}
}

void move()
{
	
	char input;
	while(1)
	{
		if (kbhit())
		{
			input = getch();
			if (input == 'w')
			{
				if (map[now_x - 1][now_y] == 1)
				{
					map[now_x][now_y] = 1;
					now_x = now_x - 1;
					map[now_x][now_y] = 3;
				}
				else if (map[now_x - 1][now_y] == 4)
				{
					printf("You are successful");
					exit(0);
				}
				break;
			}
			else if (input == 's')
			{
				if (map[now_x + 1][now_y] == 1)
				{
					map[now_x][now_y] = 1;
					now_x = now_x + 1;
					map[now_x][now_y] = 3;
				}
				else if (map[now_x + 1][now_y] == 4)
				{
					printf("You are successful");
					exit(0);
				}
				break;
			}
			else if (input == 'a')
			{
				if (map[now_x][now_y - 1] == 1)
				{
					map[now_x][now_y] = 1;
					now_y = now_y - 1;
					map[now_x][now_y] = 3;
				}
				else if (map[now_x][now_y - 1] == 4)
				{
					printf("You are successful");
					exit(0);
				}
				break;
			}
			else if (input == 'd')
			{
				if (map[now_x][now_y + 1] == 1)
				{
					map[now_x][now_y] = 1;
					now_y = now_y + 1;
					map[now_x][now_y] = 3;
				}
				else if (map[now_x][now_y + 1] == 4)
				{
					printf("You are successful");
					exit(0);
				}
				break;
			}

		}
	}
	
	gotoxy(0, 0);
	print();
	
}



int main()
{
	srand((unsigned)time(NULL));
	//printf("ÓÎÏ·¿ªÊ¼\n");
	start();
	
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 5)
			{
				map[i][j] = 1;
			}
		}
	}
	print();
	while (1)
	{
		
		move();
		
	}
	
	
	return 0;
}