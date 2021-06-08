#ifndef BRTree_H 
#define BRTree_H
#include"NodeBRTree.h"
#include"stack.h"
#include"List.h"

template <typename Key, typename Value>
class RBTree
{
private:
	Node<Key, Value>* nil = new Node<Key, Value>();
	void Insert_fixup(Node<Key, Value>* newNode)
	{

		while (newNode != Root && newNode->parent->color == 'r')
		{
			if (newNode->parent == newNode->parent->parent->Lnext)
			{
				Node<Key, Value>* y;
				y = newNode->parent->parent->Rnext;
				if (y->color == 'r') {
					newNode->parent->color = 'b';
					y->color = 'b';
					newNode->parent->parent->color = 'r';
					newNode = newNode->parent->parent;
				}
				else {
					if (newNode == newNode->parent->Rnext)
					{
						newNode = newNode->parent;
						Left_Rotate(newNode);
					}
					newNode->parent->color = 'b';
					newNode->parent->parent->color = 'r';
					Right_Rotate(newNode->parent->parent);
				}
			}
			else {
				Node<Key, Value>* y;
				y = newNode->parent->parent->Lnext;
				if (y->color == 'r') {
					newNode->parent->color = 'b';
					y->color = 'b';
					newNode->parent->parent->color = 'r';
					newNode = newNode->parent->parent;
				}
				else {
					if (newNode == newNode->parent->Lnext)
					{
						newNode = newNode->parent;
						Right_Rotate(newNode);
					}
					newNode->parent->color = 'b';
					newNode->parent->parent->color = 'r';
					Left_Rotate(newNode->parent->parent);
				}
			}
		}
		Root->color = 'b';
	}

	void Remove_fixup(Node<Key, Value>* x)
	{
		while (x != Root && x->color == 'b')
		{
			if (x == x->parent->Lnext)
			{
				Node<Key, Value>* w;
				w = x->parent->Rnext;
				if (w->color == 'r')
				{
					w->color = 'b';
					x->parent->color = 'r';
					Left_Rotate(x->parent);
					w = x->parent->Rnext;
				}
				if (w->Lnext->color == 'b' && w->Rnext->color == 'b')
				{
					w->color = 'r';
					x = x->parent;
				}
				else
				{
					if (w->Rnext->color == 'b')
					{
						w->Lnext->color = 'b';
						w->color = 'r';
						Right_Rotate(w);
						w = x->parent->Rnext;
					}
					w->color = x->parent->color;
					x->parent->color = 'b';
					w->Rnext->color = 'b';
					Left_Rotate(x->parent);
					x = Root;
				}
			}
			else
			{
				Node<Key, Value>* w;
				w = x->parent->Lnext;
				if (w->color == 'r')
				{
					w->color = 'b';
					x->parent->color = 'r';
					Right_Rotate(x->parent);
					w = x->parent->Lnext;
				}
				if (w->Rnext->color == 'b' && w->Lnext->color == 'b')
				{
					w->color = 'r';
					x = x->parent;
				}
				else
				{
					if (w->Lnext->color == 'b')
					{
						w->Rnext->color = 'b';
						w->color = 'r';
						Left_Rotate(w);
						w = x->parent->Lnext;
					}
					w->color = x->parent->color;
					x->parent->color = 'b';
					w->Lnext->color = 'b';
					Right_Rotate(x->parent);
					x = Root;
				}
			}
		}
		x->color = 'b';
	}

	void Left_Rotate(Node<Key, Value>* x)
	{
		Node<Key, Value>* y;
		y = x->Rnext;
		x->Rnext = y->Lnext;
		if (y->Lnext != nil)
		{
			y->Lnext->parent = x;
		}
		if (y != nil) {
			y->parent = x->parent;
		}
		if (x->parent == nil)
		{
			Root = y;
		}
		else if (x == x->parent->Lnext)
		{
			x->parent->Lnext = y;
		}
		else
		{
			x->parent->Rnext = y;
		}
		y->Lnext = x;
		x->parent = y;
	}

	void Right_Rotate(Node<Key, Value>* x)
	{
		Node<Key, Value>* y = new Node<Key, Value>;
		y = x->Lnext;
		x->Lnext = y->Rnext;
		if (y->Rnext != nil)
		{
			y->Rnext->parent = x;
		}
		if (y != nil) {
			y->parent = x->parent;
		}
		if (x->parent == nil)
		{
			Root = y;
		}
		else if (x == x->parent->Rnext)
		{
			x->parent->Rnext = y;
		}
		else
		{
			x->parent->Lnext = y;
		}
		y->Rnext = x;
		x->parent = y;
	}

public:

	RBTree()
	{
		Root = nil;
	}

	~RBTree()
	{
		Clear();
		nil = nullptr;
		Root = nullptr;
	}
	Node<Key, Value>* Root;
	void insert(Key key, Value value) //adding an item with a key and a value
	{
		if (Root == nil)
		{
			Node<Key, Value>* kkk = new Node<Key, Value>(key, value, 'b', nil, nil, nil);
			Root = kkk;
		}
		else {
			Node<Key, Value>* iter;
			iter = Root;
			for (;;) {
				if (key <= iter->key)
				{
					if (iter->Lnext == nil)
					{
						iter->Lnext = new Node<Key, Value>(key, value, 'r', iter, nil, nil);
						Insert_fixup(iter->Lnext);
						break;
					}
					iter = iter->Lnext;
				}
				else {
					if (iter->Rnext == nil)
					{
						iter->Rnext = new Node<Key, Value>(key, value, 'r', iter, nil, nil);
						Insert_fixup(iter->Rnext);
						break;
					}
					iter = iter->Rnext;
				}
			}
		}
	}
	 
	void remove(Key key) //deleting a tree element by key
	{
		Node<Key, Value>* y;
		Node<Key, Value>* Z;
		Node<Key, Value>* X;
		Z = Find(key);
		y = Z;
		char y_o_colour = y->color;
		if (Z->Lnext == nil) {
			X = Z->Rnext;
			Transplant(Z, Z->Rnext);
		}
		else if (Z->Rnext == nil)
		{
			X = Z->Lnext;
			Transplant(Z, Z->Lnext);
		}
		else
		{
			y = y->Rnext;
			while (y->Lnext != nil)
			{
				y = y->Lnext;
			}
			y_o_colour = y->color;
			X = y->Rnext;
			if (y->parent == Z)
			{
				X->parent = y;
			}
			else
			{
				Transplant(y, y->Rnext);
				y->Rnext = Z->Rnext;
				y->Rnext->parent = y;
			}
			Transplant(Z, y);
			y->Lnext = Z->Lnext;
			y->Lnext->parent = y;
			y->color = Z->color;
		}
		if (y_o_colour == 'b') {
			Remove_fixup(X);
		}
	}

	Node<Key, Value>* Find(Key key)//item search by key
	{
		if (Root == nullptr) 
		{
			throw "No such element exists";
		}
		else {
			Node<Key, Value>* iter;
			iter = Root;
			for (;;) {
				if (key <= iter->key) 
				{
					if (iter->key == key) 
					{
						return iter;
					}
					if (iter->Lnext == nil) 
					{
						throw "No such element exists";
					}
					iter = iter->Lnext;
				}
				else {
					if (iter->key == key) 
					{
						return iter;
					}
					if (iter->Rnext == nil) 
					{
						throw "No such element exists";
					}
					iter = iter->Rnext;
				}
			}
		}
	}

	void  Transplant(Node<Key, Value>* U, Node<Key, Value>* V)
	{
		if (U->parent == nil)
		{
			Root = V;
		}
		else if (U == U->parent->Lnext)
		{
			U->parent->Lnext = V;
		}
		else
		{
			U->parent->Rnext = V;
		}
		V->parent = U->parent;
	}

	void Clear() //clearing an associative array
	{
		Preorder(Root);
		delete nil;
		nil = nullptr;
		Root = nullptr;
	} 

	void Preorder(Node<Key, Value>* node) //wood cleaning
	{
		if (node == nullptr || node == nil) return;
		Preorder(node->Lnext);
		Preorder(node->Rnext);
		delete node;
	}

	List<Key>* Get_Keys() //returns a list of keys
	{
		if (Root == nil)
		{
			throw("There is no element");
		}
		Stack<Key, Value> stackKey;
		List<Key>* listKey = new List<Key>;
		stackKey.Push(Root);
		bool flag = true;
		Node<Key, Value>* temp = stackKey.Head->date;
		while (!stackKey.IsEmpty())
		{
			listKey->Push_Back(temp->key);
			if (temp->Rnext != nil)
			{
				if (flag)
				{
					stackKey.Pop_Front();
					flag = false;
				}
				stackKey.Push(temp->Rnext);
			}
			if (temp->Lnext != nil)
			{
				temp = temp->Lnext;
			}
			else
			{
				if (flag)
				{
					stackKey.Pop_Front();
				}
				if (!stackKey.IsEmpty())
				{
					temp = stackKey.Head->date;
				}
				flag = true;
			}
		}
		return listKey;
	}

	List<Value>* Get_Values() //returns a list of values
	{
		if (Root == nil)
		{
			throw("There is no element");
		}
		Stack<Key, Value> stackValue;
		List<Key>* listValue = new List<Key>;
		stackValue.Push(Root);
		bool flag = true;
		Node<Key, Value>* temp = stackValue.Head->date;
		while (!stackValue.IsEmpty())
		{
			listValue->Push_Back(temp->value);
			if (temp->Rnext != nil)
			{
				if (flag)
				{
					stackValue.Pop_Front();
					flag = false;
				}
				stackValue.Push(temp->Rnext);
			}
			if (temp->Lnext != nil)
			{
				temp = temp->Lnext;
			}
			else
			{
				if (flag)
				{
					stackValue.Pop_Front();
				}
				if (!stackValue.IsEmpty())
				{
					temp = stackValue.Head->date;
				}
				flag = true;
			}
		}
		return listValue;
	}

	void Print() //console output
	{
		List<Key>* ListKey = Get_Keys();
		List<Value>* ListValue = Get_Values();
		for (int i = 0; i < ListKey->Get_Size(); i++)
		{
			std::cout << ListKey->At(i) << "-" << ListValue->At(i) << std::endl;
		}
	} 
};
#endif