#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* creatempty()
{
	struct node* headnode = (struct node*)malloc(sizeof(struct node));
	headnode->data = 1;
	headnode->next = NULL;
	return headnode;
}

struct node* newnode(int data)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

void append(struct node* newnode, struct node** headnode)
{
	struct node* p;
	p = (*headnode);
	p->data = (*headnode)->data;
	p->next = (*headnode)->next;
	while (1)
	{
		if (p->next == NULL)
		{
			p->next = newnode;
			break;
		}
		else
		{
			//(*headnode) = (*headnode)->next;
			p = p->next;
		}
	}
}

void insert(struct node* newnode, struct node* headnode, int n)
{

	struct node* here;
	struct node* after;
	here = headnode;
	for (int i = 0; i < n; i++)
	{
		here = here->next;
	}
	newnode->next = here->next;
	here->next = newnode;


}

void delete(struct node* headnode, int n)
{
	struct node* p;

	p = headnode;

	for (int i = 0; i < n - 1; i++)
	{
		p = p->next;
	}
	struct node* q = p->next;
	p->next = p->next->next;
	free(q);

}

void invertion(struct node** headnode)
{
	struct node* p;
	int m = 0;
	p = (*headnode);
	while (p->next != NULL)
	{
		p = p->next;
		m++;
	}
	struct node* s = (*headnode)->next;
	struct node* q = (*headnode)->next;
	(*headnode)->next = p;
	p->next = s;
	while (p->next != NULL)
	{
		for (int i = 0; i < m - 2; i++)
		{
			q = q->next;
		}
		p->next = q;
		p = p->next;
		q = s;
		m--;
		if (m == 1)
		{
			p->next = NULL;
		}
	}
}

void print(struct node* headnode)
{
	struct node* p;
	p = headnode->next;
	while (p)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

int find(struct node* headnode)
{
	struct node* p;
	p = headnode;
	int m = 0;
	while (p->next != NULL)
	{
		p = p->next;
		m++;
	}
	p = headnode->next;
	struct node* newheadnode = creatempty();
	for (int i = 1; i <= m; i++)
	{
		if (p->next == 5)
		{
			struct node* nodei = newnode(i);
			append(nodei, &newheadnode);
		}
	}
	if (newheadnode->next == NULL) return 0;
	else return newheadnode;
}
int main()
{
	struct node* p = creatempty();
	struct node* node1 = newnode(1);
	struct node* node2 = newnode(2);
	struct node* node3 = newnode(3);
	struct node* node4 = newnode(4);
	struct node* node5 = newnode(5);
	struct node* node6 = newnode(7);
	struct node* node7 = newnode(4);
	struct node* node8 = newnode(5);
	append(node1, &p);
	append(node2, &p);
	append(node3, &p);
	//append(node4, &p);
	append(node5, &p);
	append(node6, &p);
	append(node7, &p);
	append(node8, &p);
	insert(node4, p, 1);
	print(p);
	printf("反序后的链表\n");
	//delete(p, 1);
	invertion(&p);
	print(p);
	struct node* q;
	q = find(p);
	return 0;
}