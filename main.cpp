#include "List.h"
#include "iostream"
using namespace std;

void print(List_3358 list);

int main()
{
	List_3358 list, list2;
	
	for (int i = 5; i >=0; i--)
		list.insert(i);

	list.bubbleSort();
	print(list);
	list.resetBack();
	list.backup();
	print(list2);
	list2 = list;
	print(list2);
	list2.remove();
	print(list2);
	cout << list2.getCurrent() << endl;


	


	cout << "Hello";
	system("pause"); 
	return 0;

}
void print(List_3358 list)
{
	list.resetFront();

	while (!list.atEOL())
	{
		cout << list.getCurrent() << ", ";
		list.advance();
	}
	cout << endl;
}