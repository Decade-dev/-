#include<iostream>
using namespace std;
class SeqList
{
private:
	int* list;
	int maxsize;
	int size;
public:
	SeqList()
	{
		size = 0;
		maxsize = 1000;
		list = new int[maxsize];
	}
	~SeqList()
	{
		delete[] list;
	}
	int list_size()
	{
		return size;
	}
	int list_insert(int i, int item)
	{
		if (i - 1 < 0 || i > size + 1)
		{
			return -1;
		}
		for (int j = size - 1; j >= i - 1; j--)
		{
			list[j + 1] = list[j];
		}
		list[i - 1] = item;
		size++;
		return 1;
	}
	int list_del(int i)
	{
		if (i - 1 < 0 || i > size)
		{
			return -1;
		}
		for (int j = i - 1; j < size; j++)
		{
			list[j] = list[j + 1];
		}
		size--;
		return 1;
	}
	int list_get(int i)
	{
		if (i - 1 < 0 || i > size)
		{
			return -1;
		}
		return list[i - 1];
	}
	void list_display()
	{
		cout << size << " ";
		for (int i = 0; i < size; i++)
		{
			if (i == size - 1)
			{
				cout << list[i];
			}
			else
			{
				cout << list[i] << " ";
			}
		}
	}
};
int main()
{
	int size, value, i, item;
	cin >> size;
	SeqList List;
	for (int i = 0; i < size; i++)
	{
		cin >> value;
		List.list_insert(i + 1, value);
	}
	List.list_display();
	cin >> i >> item;
	if (List.list_insert(i, item) == 1)
	{
		List.list_display();
	}
	else
	{
		cout << "error" << endl;
	}
	cin >> i >> item;
	if (List.list_insert(i, item) == 1)
	{
		List.list_display();
	}
	else
	{
		cout << "error" << endl;
	}
	cin >> i;
	if (List.list_del(i) == 1)
	{
		List.list_display();
	}
	else
	{
		cout << "error" << endl;
	}
	cin >> i;
	if (List.list_del(i) == 1)
	{
		List.list_display();
	}
	else
	{
		cout << "error" << endl;
	}
	cin >> i;
	if (List.list_get(i) == -1)
	{
		cout << "error";
	}
	else
	{
		cout << List.list_get(i) << endl;
	}
	cin >> i;
	if (List.list_get(i) == -1)
	{
		cout << "error";
	}
	else
	{
		cout << List.list_get(i) << endl;
	}
}