#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#define M 11
int map[M][M] = { 0 };
int num;
int i = 0, j = 0;
int now_x = 1, now_y = 1;
int level=0;
int ans = 0;
int* p=NULL;

void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}


void start()
{	
	int n = 11;
	if (level == 1)
	{
		FILE* fp;
		fp = fopen("1.txt", "r");
		rewind(fp);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				fscanf(fp, "%d", &map[i][j]);
			}
		}
		fclose(fp);
	}
	if (level == 2)
	{
		FILE* fp;
		fp = fopen("2.txt", "r");
		rewind(fp);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				fscanf(fp, "%d", &map[i][j]);
			}
		}
		fclose(fp);
	}
	if (level == 3)
	{
		FILE* fp;
		fp = fopen("3.txt", "r");
		rewind(fp);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				fscanf(fp, "%d", &map[i][j]);
			}
		}
		fclose(fp);
	}
}

void turn()
{
	if (level == 1)
	{
		FILE* fp;
		fp = fopen("��һ�سɼ�.txt", "w");
		rewind(fp);
		fprintf(fp, "%d", *p);
		fclose(fp);
	}
	if (level == 2)
	{
		FILE* fp;
		fp = fopen("�ڶ��سɼ�.txt", "w");
		fprintf(fp, "%d",ans);
		fclose(fp);
	}
	if (level == 3)
	{
		FILE* fp;
		fp = fopen("�����سɼ�.txt", "w");
		fprintf(fp, "%d", ans);
		fclose(fp);
	}
}
void print()
{

	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				printf("��");
			}
			else if (map[i][j] == 1)
			{
				printf("  ");
			}
			else if (map[i][j] == 3)
			{
				printf("��");
			}
			else if (map[i][j] == 5)
			{
				printf("��");
			}
			else if (map[i][j] == 2)
			{
				printf("��");
			}
			else if (map[i][j] == 4)
			{
				printf("��");
			}	
		}
		printf("\n");
	}
}
//void print()
//{
//	for (int i = 0; i < 11; i++)
//	{
//		for (int j = 0; j < 11; j++)
//		{
//			printf("%d", map[i][j]);
//		}
//		printf("\n");
//	}
//}

void move()
{

	char input;
	while (1)
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
				else if (map[now_x - 1][now_y] == 2&& map[now_x - 2][now_y] != 0 && map[now_x - 2][now_y] != 2)
				{
					map[now_x][now_y] = 1;
					now_x = now_x - 1;
					map[now_x][now_y] = 3;
					map[now_x - 1][now_y] = 2;
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
				else if (map[now_x + 1][now_y] == 2 && map[now_x + 2][now_y] != 0 && map[now_x + 2][now_y] != 2)
				{
					map[now_x][now_y] = 1;
					now_x = now_x + 1;
					map[now_x][now_y] = 3;
					map[now_x+1][now_y] = 2;
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
				else if (map[now_x][now_y - 1] == 2&& map[now_x][now_y - 2] != 0 && map[now_x][now_y - 2] != 2)
				{
					
					map[now_x][now_y] = 1;
					now_y = now_y - 1;
					map[now_x][now_y] = 3;
					map[now_x][now_y - 1] = 2;
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
				else if (map[now_x][now_y + 1] == 2&& map[now_x][now_y + 2] != 0 && map[now_x][now_y + 2] != 2)
				{
					
					
					map[now_x][now_y] = 1;
					now_y = now_y + 1;
					map[now_x][now_y] = 3;
					map[now_x][now_y + 1] = 2;
				}
				break;
			}
			else if (input == 27)
			{
				exit(0);
			}

		}
	}

	gotoxy(0, 0);
	print();
}

int main()
{
	
	while (1)
	{
		system("cls");
		ans = 0;
		level++;
		if (level == 4) 
		{
			printf("����ͨ�أ�");
			exit(0);

		}
		start();
		print();
		printf("��%d��\n", level);
		printf("������κ����⣬�밴Esc�˳���Ϸ\n");
		
		while (1)
		{
			int flag = 0;
			move();
			
			ans++;
			gotoxy(0, 13);
			printf("��ǰ�ߵĲ���Ϊ%d\n", ans);
			for (i = 0; i < M; i++)
			{
				for (j = 0; j < M; j++)
				{
					if (map[i][j] == 4)
						flag = 1;
				}
			}
			if (flag == 0)
			{
				now_x = 1;
				now_y = 1;
				p =&ans;
				turn();
				break;
			}
		}
		
	}
	return 0;
}