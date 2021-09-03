#include <iostream>
using namespace std;
class ListNode
{
public:
	int date = 0;
	ListNode* next;
	ListNode()
	{
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
	void init_list()
	{
		int val, len;
		ListNode* p = head;
		cin >> len;
		this->len = len;
		for (int i = 0; i < len; i++)
		{
			cin >> val;
			ListNode* pNew = new ListNode();
			pNew->next = NULL;
			pNew->date = val;
			p->next = pNew;
			p = pNew;
		}
	}
	int insert_list(int i, int item)
	{
		int j = 0;
		ListNode* p = head;
		while (j < i - 1 && p != NULL)
		{
			p = p->next;
			j++;
		}
		if (j > i - 1 || p == NULL)
		{
			return -1;
		}
		ListNode* pNew = new ListNode();
		pNew->date = item;
		pNew->next = p->next;
		p->next = pNew;
		len++;
		return 1;
	}
	int delete_list(int i)
	{
		int j = 0;
		ListNode* p = head;
		while (j < i - 1 && p->next != NULL)
		{
			p = p->next;
			j++;
		}
		if (j > i - 1 || p->next == NULL)
		{
			return -1;
		}
		ListNode* pp = p->next;
		p->next = p->next->next;
		delete pp;
		pp = NULL;
		return 1;
	}
	int find_list(int i)
	{
		int j = 1;
		if (i < 1 || i > len)
		{
			return -1;
		}
		ListNode* p = head->next;
		while (j < i)
		{
			p = p->next;
			j++;
		}
		return p->date;
	}
	void display()
	{
		ListNode* p;
		p = head->next;
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
	int i, item;
	LinkList List;
	List.init_list();
	List.display();
	cin >> i >> item;
	if (List.insert_list(i, item) == -1)
		cout << "error" << endl;
	else
	{
		List.display();
	}
	cin >> i >> item;
	if (List.insert_list(i, item) == -1)
		cout << "error" << endl;
	else
	{
		List.display();
	}
	cin >> i;
	if (List.delete_list(i) == -1)
		cout << "error" << endl;
	else
	{
		List.display();
	}
	cin >> i;
	if (List.delete_list(i) == -1)
		cout << "error" << endl;
	else
	{
		List.display();
	}
	cin >> i;
	if (List.find_list(i) == -1)
		cout << "error" << endl;
	else
	{
		cout << List.find_list(i) << endl;
	}
	cin >> i;
	if (List.find_list(i) == -1)
		cout << "error" << endl;
	else
	{
		cout << List.find_list(i) << endl;
	}
	return 0;
}
	