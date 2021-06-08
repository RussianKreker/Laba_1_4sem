#ifndef List_H
#define List_H
template <typename Data>
class List
{
public:
	 
	List()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	 
	~List()
	{
		Clear();
	}
	 
	void Reset_List()
	{
		tail = nullptr;
		head = nullptr;
	}
	 
	unsigned int Get_Size()
	{
		return size;
	}
	 
	void Push_Back(Data date)
	{
		if (size == 0)
		{
			head = new ListNode(date);
			tail = head;
		}
		else {
			tail->next = new ListNode(date);
			tail = tail->next;
		}
		size++;
	}
	 
	void Push_Front(Data date)
	{
		if (size == 0)
		{
			head = new ListNode(date);
			tail = head;
		}
		else {
			head = new ListNode(date, head);
		}
		size++;
	}
	 
	void Pop_Back()
	{
		if (size == 0) return;
		if (size == 1)
		{
			delete head;
			Reset_List();
		}
		else
		{
			Node* current = head;
			while (current->next != tail)
			{
				current = current->next;
			}
			current->next = nullptr;
			delete tail;
			tail = current;
		}
		size--;
	}
	 
	void Pop_Front()
	{
		if (size == 0)
		{
			return;
		}
		if (size == 1)
		{
			delete head;
			Reset_List();
		}
		else {
			ListNode* current = head;
			head = head->next;
			delete current;
		}
		size--;
	}
	 
	void Print_to_Console()
	{
		if (size == 0)
		{
			return;
		}
		else
		{
			unsigned int index = Get_Size();
			ListNode* current = head;
			while (index != 0) {
				std::cout << current->value << " ";
				current = current->next;
				index--;
			}
			std::cout << std::endl;
		}
	}
	 
	void Clear()
	{
		while (size != 0)
		{
			Pop_Front();
		}
	}
	 
	bool IsEmpty()
	{
		if (size != 0) {
			return 0;
		}
		return 1;
	}
	 
	Data At(unsigned int index)
	{
		if (index >= size)
		{
			throw std::out_of_range("Index is greater than list size");
		}
		else {
			ListNode* current = head;
			unsigned int counter = 0;
			while (counter != index)
			{
				current = current->next;
				counter++;
			}
			return current->data;
		}
	}

private:
	class ListNode 
	{
	public:
		Data data;
		ListNode* next;
		ListNode(Data data, ListNode* next = nullptr)
		{
			this->data = data;
			this->next = next;
		};
		~ListNode(){}
	};
	ListNode* tail;
	ListNode* head;
	unsigned int size;
};
#endif
