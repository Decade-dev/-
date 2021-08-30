#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct node
{
	int date;
	struct node *pNext;
}NODE,*PNODE;
typedef struct stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK,*PSTACK;
void init_stack(PSTACK);
void push_stack(PSTACK,int);
void pop_stack(PSTACK,int *);
void traverse_stack(PSTACK);
void clear_stack(PSTACK);
bool empty(PSTACK);
int main(void)
{
	int val;
	STACK p;
	init_stack(&p);
	push_stack(&p,5);
	push_stack(&p,6);
	push_stack(&p,7);
	pop_stack(&p,&val);
	traverse_stack(&p);
	printf("%d\n",val);
	clear_stack(&p);
	return 0;
} 
void init_stack(PSTACK ps)
{
	PNODE pp = (PNODE)malloc(sizeof(NODE));
	if(pp == NULL)
	{
		printf("动态创建内存失败");
		exit(-1); 
	}
	else
	{
		ps->pTop = pp;
		ps->pBottom = ps->pTop;
		return; 
	}
}
void push_stack(PSTACK ps,int val)
{
	PNODE pp = (PNODE)malloc(sizeof(NODE));
	pp->date = val;
	pp->pNext = ps->pTop;
	ps->pTop = pp;
	return;
}
void pop_stack(PSTACK ps,int *val)
{
	PNODE pp = ps->pTop;
	*val = pp->date;
	ps->pTop = pp->pNext;
	free(pp);
	pp = NULL; 	
	return;
}
void traverse_stack(PSTACK ps)
{
	if(empty(ps))
	{
		return;
	}
	else
	{
	PNODE pp = ps->pTop;
	while(pp != ps->pBottom)
	{
		printf("%d ",pp->date);
		pp = pp->pNext;
	}
	return;
	}	
}
bool empty(PSTACK ps)
{
	if (ps->pTop == ps->pBottom)
		return true;
	else
		return false;
}
void clear_stack(PSTACK ps)
{
	if(empty(ps))
	{
		return;
	}
	else
	{
		PNODE pp = ps->pTop;
		PNODE ppp = NULL;
		while(pp != ps->pBottom)
		{
			ppp = pp->pNext;
			free(pp);
			pp = ppp; 
		}
		return;
	}
	ps->pTop = ps->pBottom; 
}
