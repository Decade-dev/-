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
		delete [] list;
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
		list[i - 1] = item;//±ğÍüÁËĞ´
		size++;
		return 1;
	}
	int list_get(int i)
	{
		return list[i - 1];
	}
	void list_combine(SeqList& s1, SeqList& s2)
	{
		int i = 1;
		int j = 1;
		while (i <= s1.list_size() && j <= s2.list_size())
		{
			if (s1.list_get(i) < s2.list_get(j))
			{
				list[size++] = s1.list_get(i++);
			}
			else
			{
				list[size++] = s2.list_get(j++);
			}
		}
		if (i <= s1.list_size())
		{
			while(i <= s1.list_size())
			list[size++] = s1.list_get(i++);
		}
		if (j <= s2.list_size())
		{
			while(j <= s2.list_size())
			list[size++] = s2.list_get(j++);
		}
	}
	void display()
	{
		cout << size << " ";
		for (int i = 0; i < size; i++)
		{
			if (i == size - 1)
			{
				cout << list[i] << endl;
			}
			else
			cout << list[i] << " ";
		}
	}
};
int main()
{
	SeqList s1;
	SeqList s2;
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int value;
		cin >> value;
		s1.list_insert(i, value);
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int value;
		cin >> value;
		s2.list_insert(i, value);
	}
	SeqList s3;
	s3.list_combine(s1, s2);
	s3.display();
	return 0;
}
