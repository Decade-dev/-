#include<iostream>
using namespace std;
class SeqList
{
private:
	int* list;
	int maxsize;
	int size;
public:
	SeqList(int size)
	{
		this->size = size;
		maxsize = 1000;
		list = new int[size];
	}
	~SeqList()
	{
		delete [] list;
	}
	void init_list()
	{
		int value;
		for (int i = 0; i < size; i++)
		{
			cin >> value;
			list[i] = value;
		}
	}
	int multiinsert(int i, int n, int item[])
	{
		if (i - 1 < 0 || i - 1 > size)
		{
			return -1;
		}
		for (int m = 0; m < n; m++)
		{
			for (int j = size - 1; j >= i - 1; j--)
			{
				list[j + 1] = list[j];
			}
			size++;
		}
		for (int m = 0; m < n; m++)
		{
			list[i + m - 1] = item[m];
		}
		return 1;
	}
	int multidel(int i, int n)
	{
		if (i - 1 < 0 || i - 1 > size - n)
		{
			return -1;
		}
		for (int m = 0; m < n; m++)
		{
			for (int j = i - 1; j <= size - 1; j++)
			{
				list[j] = list[j + 1];
			}
			size--;
		}
		return 1;
	}
	void list_display()
	{
		cout << size << " ";
		for (int i = 0; i < size; i++)
		{
			if (i == size - 1)
			{
				cout << list[i] << endl;
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
	int size,item[1000],k,i;//i表示位置，k表示插入或者删除的数量
	cin >> size;
	SeqList List(size);
	List.init_list();
	List.list_display();
	cin >> i >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> item[i];
	}
	if (List.multiinsert(i, k, item) == -1)
	{
		cout << "error" << endl;
	}
	else
	{
		List.list_display();
	}
	cin >> i >> k;
	if (List.multidel(i, k) == -1)
	{
		cout << "error" << endl;
	}
	else
	{
		List.list_display();
	}
	return 0;
}