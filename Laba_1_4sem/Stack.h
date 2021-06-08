#ifndef stack_H
#define stack_H
#include"BRTree.h"
#include"NodeBRTree.h"
template <typename Key, typename Value>
class Stack
{

private:
	class StackNode 
	{
	public:
		Node<Key, Value>* date;
		StackNode* next;

		StackNode(Node<Key, Value>* date = nullptr, StackNode* next = nullptr)
		{
			this->date = date;
			this->next = next;
		};
		~StackNode()
		{

		}
	};

public:
	StackNode* Head;
	StackNode* Tail;
	unsigned int Size;


	Stack()
	{
		Head = nullptr;
		Tail = nullptr;
		Size = 0;
	}

	~Stack()
	{
		Clear();
	}

	void Clear()
	{
		while (Size != 0)
		{
			Pop_Front();
		}
	}

	bool IsEmpty()
	{
		if (Size != 0)
		{
			return 0;
		}
		return 1;
	}

	void Push(Node<Key, Value>* date)
	{
		if (Size == 0)
		{
			Head = new StackNode(date);
			Tail = Head;
		}
		else
		{
			Head = new StackNode(date, Head);
		}
		Size++;
	}

	void Pop_Front()
	{
		if (Size == 0)
		{
			return;
		}
		if (Size == 1)
		{
			delete Head;
			Reset_List();
		}
		else
		{
			StackNode* current = Head;
			Head = Head->next;
			delete current;
		}
		Size--;

	}

	void Pop_Back()
	{
		if (Size == 0) return;
		if (Size == 1)
		{
			delete Head;
			Reset_List();
		}
		else {
			StackNode* current = Head;
			while (current->next != Tail)
			{
				current = current->next;
			}
			current->next = nullptr;
			delete Tail;
			Tail = current;
		}
		Size--;
	}

	void Reset_List()
	{
		Head = nullptr;
		Tail = nullptr;
	}
};
#endif