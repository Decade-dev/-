#include <stdio.h>
#include <malloc.h>
struct TNODE
{
	int date;
	struct TNODE * Left;
	struct TNODE * Right;
}; 
struct TNODE* unit_tree(void);
void preTraverse_tree(struct TNODE*);
void inTraverse_tree(struct TNODE*); 
void pastTraverse_tree(struct TNODE*); 
int main(void)
{
	struct TNODE *tree = unit_tree(); 
	preTraverse_tree(tree);
	inTraverse_tree(tree);
	pastTraverse_tree(tree);
} 
struct TNODE *unit_tree(void)
{
	struct TNODE *pNode = (struct TNODE*)malloc(sizeof(struct TNODE));
	struct TNODE *p1 = (struct TNODE*)malloc(sizeof(struct TNODE));
	struct TNODE *p2 = (struct TNODE*)malloc(sizeof(struct TNODE));
	struct TNODE *p3 = (struct TNODE*)malloc(sizeof(struct TNODE));
	struct TNODE *p4 = (struct TNODE*)malloc(sizeof(struct TNODE));
	pNode->date = 0;
	p1->date = 1;
	p2->date = 2;
	p3->date = 3;
	p4->date = 4;
	pNode->Left = p1;
	p1->Left = p1->Right = NULL;
	pNode->Right = p2;
	p2->Right = NULL;
	p2->Left = p3;
	p3->Left = NULL;
	p3->Right = p4;
	p4->Left = p4->Right = NULL;
	return  pNode;
}
void preTraverse_tree(struct TNODE* pNode)
{
	if(pNode != NULL)
	{
		printf("%d",pNode->date);
		if(pNode->Left != NULL)
		{
			preTraverse_tree(pNode->Left);
		}
		if(pNode->Right != NULL)
		{
			preTraverse_tree(pNode->Right);
		}
	}
}
void inTraverse_tree(struct TNODE* pNode)
{
	if(pNode != NULL)
	{
		if(pNode->Left != NULL)
		{
			preTraverse_tree(pNode->Left);
		}
		printf("%d",pNode->date);
		if(pNode->Right != NULL)
		{
			preTraverse_tree(pNode->Right);
		}
	}
}
void pastTraverse_tree(struct TNODE* pNode)
{
	if(pNode != NULL)
	{
		if(pNode->Left != NULL)
		{
			preTraverse_tree(pNode->Left);
		}
		if(pNode->Right != NULL)
		{
			preTraverse_tree(pNode->Right);
		}
		printf("%d",pNode->date); 
	}
}
