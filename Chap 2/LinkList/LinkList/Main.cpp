#include <iostream>
#include "LinkList.h"
using namespace std;
void visit(int& e)
{
	cout << e << endl;
}
int main()
{
	LinkList<int> l1, l2;

	l1.InsertBefore(1, 1);
	l1.InsertBefore(2, 2);
	l2.InsertBefore(1, 3);
	l2.InsertBefore(2, 4);

	int t = 0;
	l1.Delete(1, t);

	l1 = l2;

	l1.Traverse(visit);
	
	l1.Clear();

	getchar();
	return 0;
}