#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>


struct menu
{
	int type;
	int number;
	struct menu* next;
};

struct menu* start()
{
	struct menu* head = (struct menu*)malloc(sizeof(struct menu));
	head->number = 0;
	head->type = 0;
	head->next = NULL;
	return head;
}

struct menu* newmenu(int type,int number)
{
	struct menu* newmenu = (struct menu*)malloc(sizeof(struct menu));
	newmenu->number = number;
	newmenu->type = type;
	newmenu->next = NULL;
	return newmenu;
}

void append(struct menu** head, struct menu* newmenu)
{
	struct menu* p;
	p = (*head);
	while (1)
	{
		if (p->next == NULL)
		{
			p->next = newmenu;
			break;
		}
		else
		{
			p = p->next;
		}
	}
}

void find(struct menu* head, int type,int number)
{
	int flag=0;
	struct menu* p;
	p = head;
	while (p->next != NULL)
	{
		p = p->next;
		if (p->type == type)
		{
			p->number = p->number + number;
			flag = 1;
		}
		
	}
	if (flag == 0)
	{
		struct menu* q = newmenu(type,number);
		append(&head,q);
	}
	else
	{
		flag = 0;
	}

}

void delet(struct menu*head,int type,int number)
{
	struct menu* p;
	struct menu* last;
	p = head->next;
	last = head;
	while (p->type != type)
	{
		p=p->next;
		last = last->next;
	}
	if (p->number - number > 0)
	{
		p->number = p->number - number;
	}
	else
	{
		last->next = p->next;
		free(p);
	}
}
void print(struct menu* head)
{
	
	printf("存货列表如下:\n");
	struct menu* p;
	p = head;
	while (p->next != NULL)
	{
		p = p->next;
		printf("type:%d   number:%d\n", p->type, p->number);
	}
	system("pause");
}

void read(struct menu* head)
{
	int m=0;
	FILE* fp;
	fp = fopen("订单.txt", "r");
	rewind(fp);
	fscanf(fp, "%d", &m);
	struct menu* p;
	for (int i = 0; i < m; i++)
	{
		int x=0, y=0;
		fscanf(fp, "%d", &x);
		fscanf(fp, "%d", &y);
		p = newmenu(x,y);
		append(&head, p);
	}
	fclose(fp);
}

void show()
{
	printf("1、显示存货列表\n");
	printf("\n");
	printf("2、入库\n");
	printf("\n");
	printf("3、出库\n");
	printf("\n");
	printf("4、退出程序\n");
	printf("\n");
	printf("请输入 1 2 3 4 进行操作");
}

int count(struct menu* head)
{
	int m = 0;
	struct menu* p;
	p = head;
	while (p->next != NULL)
	{
		p = p->next;
		m++;
	}
	return m;
}

void turn(struct menu* head)
{
	FILE* fp;
	int m = 0;
	fp = fopen("订单.txt", "w");
	rewind(fp);
	m = count(head);
	struct menu* p;
	p = head->next;
	fprintf(fp, "%d\n", m);
	for (int i = 0; i < m; i++)
	{
		fprintf(fp, "%d %d\n", p->type, p->number);
		p = p->next;
	}
	fclose(fp);
}

void input(struct menu*p)
{
	
	char input;
	while(1)
	{
		if (kbhit())
		{
			input = getch();
			if (input == '1') 
			{ 
				system("cls");
				print(p);
				break;
			}
			else if (input == '2')
			{
				system("cls");
				int type, number;
				printf("请输入进货的型号及数量\n");
				printf("型号:");
				scanf("%d", &type);
				printf("数目:");
				scanf("%d", &number);
				/*struct menu* q = newmenu(type, number);
				append(&p, q);*/
				find(p, type, number);
				break;
			}
			else if (input == '3')
			{
				system("cls");
				int type, number;
				printf("请输入要出货的型号及数量\n");
				printf("型号:");
				scanf("%d", &type);
				printf("数目:");
				scanf("%d", &number);
				delet(p, type, number);
				break;
			}
			else if (input == '4')
			{
				turn(p);
				exit(0);
			}
		}
	}
}

int main()
{
	struct menu* p = start();
	read(p);
	while (1)
	{
		system("cls");
		show();
		input(p);
	}
	return 0;
}