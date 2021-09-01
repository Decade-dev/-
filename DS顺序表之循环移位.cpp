#include <iostream>
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
		maxsize = 1000;
		size = 0;
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
		if (i - 1 < 0 || i - 1 > size)
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
	void cicle_move(int flag, int num)
	{
		if (flag == 0)
		{
			for (int i = 0; i < num; i++)
			{
				int value = list[0];
				for (int j = 0; j < size - 1; j++)
				{
					list[j] = list[j + 1];
				}
				list[size - 1] = value;
			}
		}
		if (flag == 1)
		{
			for (int i = 0; i < num; i++)
			{
				int value = list[size - 1];
				for (int j = size - 1; j > 0; j--)
				{
					list[j] = list[j - 1];
				}
				list[0] = value;
			}
		}
	}
	void diplay()
	{
		for (int i = 0; i < size; i++)
		{
			if (i == size - 1)
				cout << list[i] << endl;
			else
				cout << list[i] << " ";
		}
	}
};
int main()
{
	SeqList List;
	int n,value,flag,num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		List.list_insert(i + 1, value);
	}
	List.diplay();
	cin >> flag >> num;
	List.cicle_move(flag, num);
	List.diplay();
	cin >> flag >> num;
	List.cicle_move(flag, num);
	List.diplay();
	return 0;
}