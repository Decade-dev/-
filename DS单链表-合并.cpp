#include <iostream>
using namespace std;
class ListNode
{
public:
	int data;
	ListNode* next;
	ListNode()
	{
		data = 0;
		next = NULL;
	}
};
class LinkList
{
public:
	ListNode* head;
	int len;
	LinkList()
	{
		head = new ListNode();
		len = 0;
	}
	~LinkList()
	{
		ListNode* p, * q;
		p = head;
		while (p != NULL)
		{
			q = p;
			p = p->next;
			delete q;
		}
		len = 0;
		head = NULL;
	}
	ListNode* LL_index(int i)
	{
		int j = 0;
		if (i < 0 || i > len)
		{
			return NULL;
		}
		ListNode* p = head;
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
		return p->data;
	}
	int LL_insert(int i, int item)
	{
		if (i <= 0 || i > len + 1)
		{
			return -1;
		}
		ListNode* p = LL_index(i - 1);
		ListNode* pNew = new ListNode();
		pNew->data = item;
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
	int LL_merge(ListNode* p1, ListNode* p2)
	{
		ListNode* p = head;
		while (p1 != NULL && p2 != NULL)
		{
			if (p1->data < p2->data)
			{
				ListNode* temp = new ListNode();
				temp->data = p1->data;
				temp->next = NULL;
				p->next = temp;
				p = p->next;
				p1 = p1->next;
				len++;
			}
			if (p1->data > p2->data)
			{
				ListNode* temp = new ListNode();
				temp->data = p2->data;
				temp->next = NULL;
				p->next = temp;
				p = p->next;
				p2 = p2->next;
				len++;
			}
		}
		while (p1 != NULL)
		{
			ListNode* temp = new ListNode();
			temp->data = p1->data;
			temp->next = NULL;
			p->next = temp;
			p = p->next;
			p1 = p1->next;
			len++;
		}
		while (p2 != NULL)
		{
			ListNode* temp = new ListNode();
			temp->data = p2->data;
			temp->next = NULL;
			p->next = temp;
			p = p->next;
			p2 = p2->next;
			len++;
		}
	}
	void display()
	{
		ListNode* p;
		p = head->next;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
};
int main()
{
	LinkList p1, p2, p3;
	int n, m, val;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		p1.LL_insert(i, val);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> val;
		p2.LL_insert(i, val);
	}
	p3.LL_merge(p1.head->next, p2.head->next);
	p3.display();
	return 0;
}
