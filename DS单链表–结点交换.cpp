#include <iostream>
using namespace std;
class ListNode
{
public:
	int date;
	ListNode* next;
	ListNode()
	{
		date = 0;
		next = NULL;
	}
};
class LinkList
{
public:
	ListNode* pHead;
	int len;
	LinkList()
	{
		pHead = new ListNode();
		len = 0;
	}
	~LinkList()
	{
		ListNode* p, * q;
		p = pHead;
		while (p != NULL)
		{
			q = p;
			p = p->next;
			delete q;
		}
		len = 0;
		pHead = NULL;
	}
	ListNode *LL_index(int i)
	{
		if (i < 0 || i > len)
			return NULL;
		int j = 0;
		ListNode* p = pHead;
		while (j < i)
		{
			p = p->next;
			j++;
		}
		return p;
	}
	int LL_get(int i)
	{
		ListNode* p = LL_index(i);
		return p->date;
	}
	int LL_insert(int i, int item)
	{
		if (i <= 0 || i > len + 1)
		{
			return -1;
		}
		ListNode* p = LL_index(i - 1);
		ListNode* pNew = new ListNode();
		pNew->date = item;
		pNew->next = p->next;
		p->next = pNew;
		len++;
		return 1;
	}
	int LL_del(int i)
	{
		if (i <= 0 || i > len)
		{
			return -1;
		}
		ListNode* p = LL_index(i - 1);
		ListNode* q = p->next;
		p->next = q->next;
		delete q;
		return 1;
	}
	int swap(int p1, int p2)
	{
		if ((p1 < 0 || p1 > len) || (p2 < 0 || p2 > len))
		{
			return -1;
		}
		ListNode* p1_point = LL_index(p1);
		ListNode* p2_point = LL_index(p2);
		ListNode* p1_frontpoint = LL_index(p1 - 1);
		ListNode* p2_frontpoint = LL_index(p2 - 1);
		ListNode* p = p2_point->next;
		p2_point->next = p1_point->next;
		p1_frontpoint->next = p2_point;
		p2_frontpoint->next = p1_point;
		p1_point->next = p;
		return 1;
	}
	void display()
	{
		ListNode* p;
		p = pHead->next;
		while (p != NULL)
		{
			cout << p->date << " ";
			p = p->next;
		}
		cout << endl;
	}
};
int main()
{
	int n,item;
	int p1, p2;
	LinkList head;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> item;
		head.LL_insert(i + 1, item);
	}
	head.display();
	cin >> p1 >> p2;
	if (head.swap(p1, p2) == -1)
	{
		cout << "error" << endl;
	}
	else
	{
		head.display();
	}
	cin >> p1 >> p2;
	if (head.swap(p1, p2) == -1)
	{
		cout << "error" << endl;
	}
	else
	{
		head.display();
	}
	return 0;
}