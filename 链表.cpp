#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct node
{
	int date;
	struct node * pNext;
}NODE,*PNODE;
PNODE create_list(void);
void traverse_list(PNODE pHead);
void sort_list(PNODE pHead); 
bool is_empty(PNODE pHead);
bool insert_list(PNODE pHead,int pos,int val);
bool delete_list(PNODE pHead,int pos,int *val); 
int length_list(PNODE pHead); 
int main(void)
{
	int val;
	PNODE pHead = NULL;
	pHead = create_list();
	if(is_empty(pHead))
	printf("链表空");
	else
	printf("链表没空"); 
	int len = length_list(pHead);
	printf("%d",len); 
	sort_list(pHead);
	traverse_list(pHead);
	bool is_insert = insert_list(pHead,4,3);
	bool is_delete = delete_list(pHead,3,&val);
	traverse_list(pHead);
	return 0;
}
PNODE create_list(void)
{
	int len;
	int i;
	int val;
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	PNODE p = pHead;
	p->pNext = NULL;
	printf("请输入链表节点的个数 ");
	scanf("%d",&len); 
	for(i = 0; i < len; i++)
	{
		printf("请输入链表节点%d的内容 ",i+1);
		scanf("%d",&val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		pNew->pNext = NULL;
		pNew->date = val;
	    p->pNext = pNew;
		p = pNew;
	}
	return pHead; 
} 
void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	while(p != NULL)
	{
		printf("请输入链表节点的内容 ");
		printf("%d\n",p->date);
		p = p->pNext;
	}
	return;
}
void sort_list(PNODE pHead)
{
	int i,j,t;
	int len = length_list(pHead);
	PNODE p ,pp;
	for(i = 0, p = pHead->pNext; i < len - 1; i++,p = p->pNext)
	{
		for(j = i + 1, pp = p->pNext; j < len; j++,pp = pp->pNext)
		{
			if(p->date > pp->date)
			{
				t = pp->date;
				pp->date = p->date;
				p->date = t;	
			}
		}
	}
}
bool is_empty(PNODE pHead)
{
	if(pHead->pNext != NULL)
	return false;
	else
	return true;
}
bool insert_list(PNODE pHead,int pos,int val)
{
	int i = 0;
	PNODE p = pHead;
	while(i < pos - 1 && p != NULL)
	{
		p = p->pNext;
		i++;
	}
	if(i > pos - 1 || p == NULL)
	return false;
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(pNew == NULL)
	{
		printf("动态内存分配失败\n");
		exit(-1); 
	}
	pNew->date = val;
	PNODE pp = p->pNext;
	p->pNext = pNew;
	pNew->pNext = pp;
	return true;
}
bool delete_list(PNODE pHead,int pos,int *val)
{
	int i = 0;
	PNODE p = pHead;
	while(i < pos - 1 && p->pNext != NULL)
	{
		p = p->pNext;
		i++;
	}
	if(i > pos - 1 || p->pNext == NULL)
	return false;
	PNODE pp = p->pNext;
	p->pNext = p->pNext->pNext;
	free(pp);
	pp = NULL;
	return true; 
}
int length_list(PNODE pHead)
{
	int len = 0;
	PNODE p = pHead->pNext;
	while(p != NULL)
	{
		len++;
		p = p->pNext;
	}
	return len;
}
