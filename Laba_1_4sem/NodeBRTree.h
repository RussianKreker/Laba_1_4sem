#ifndef NodeBRTree_H
#define NodeBRTree_H
#include<iostream>
template <typename Key, typename Value>
class Node 
{
	public:
	Key key;
	Value value;
	char color;
	Node* Lnext;
	Node* Rnext;
	Node* parent;

	Node(Key key, Value value, char color = 'b', Node* parent = nullptr, Node* Lnext = nullptr, Node* Rnext = nullptr)
	{
		this->key = key;
		this->value = value;
		this->color = color;
		this->parent = parent;
		this->Lnext = Lnext;
		this->Rnext = Rnext;
	};

	Node(char color = 'b', Node* parent = nullptr, Node* Lnext = nullptr, Node* Rnext = nullptr)
	{
		this->color = color;
		this->parent = parent;
		this->Lnext = Lnext;
		this->Rnext = Rnext;
	};

	~Node()
	{
		value = NULL;
		key = NULL;
		color = NULL;
		Lnext = nullptr;
		Rnext = nullptr;
		parent = nullptr;
	}

};
#endif