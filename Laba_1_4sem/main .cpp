#include"BRTree.h"
#include<iostream>
using namespace std;

int main() {
	RBTree<int, int>* Tree = new RBTree<int, int>;
	for (int i = 0; i < 10; i++)
	{
		Tree->insert(i,i*10);
	}
	Tree->Print();
	cout << endl;
	cout << "Delete list element at 2 index" << endl;
	Tree->remove(2);
	Tree->Print();
	cout << std::endl;
	cout << Tree->Find(3)->value << endl;
	return 0;
}