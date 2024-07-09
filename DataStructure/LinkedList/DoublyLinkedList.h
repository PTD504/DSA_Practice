// Doubly Linked List: Each node has two poTers, one poTing to the next node and one poTing to the previous node.

template <typename T>
class DoublyLinkedList
{
private:
	struct ListNode
	{
		T data;
		struct ListNode * next;
		struct ListNode * prev;

		ListNode(T val) {
			data = val;
			prev = next = nullptr;
		}
	};

private:
	struct ListNode * head;

public:
	
	DoublyLinkedList() {
		this->head = nullptr;
	}

	void push_front(T);
	void push_back(T);
	void push_after(T, T);
	void deleteNode(T);
	void reverse();
	void traverse();

	~DoublyLinkedList() {
    ListNode * current = head;
    while (current) {
        ListNode * temp = current;
        current = current->next;
        delete temp;
    }
}
};

template <typename T>
void DoublyLinkedList<T>::push_front(T data) {
	if (this->head == nullptr) {
		this->head = new ListNode(data);
		return;
	}

	ListNode * NewNode = new ListNode(data);
	NewNode->next = this->head;
	this->head->prev = NewNode;

	this->head = NewNode;	
}

template <typename T>
void DoublyLinkedList<T>::push_back(T data) {
	if (this->head == nullptr) {
		this->head = new ListNode(data);
		return;
	}

	ListNode * NewNode = new ListNode(data);
	ListNode * temp = this->head;

	while (temp->next) temp = temp->next;

	temp->next = NewNode;
	NewNode->prev = temp;
}

template <typename T>
void DoublyLinkedList<T>::push_after(T node, T data) {
	if (this->head == nullptr) {
		std::cout << "The ListNode with value " << node << " does not exist in the linked list\n";
		return;
	}

	ListNode * temp = this->head;
	ListNode * NewNode = new ListNode(data);

	while (temp->data != node) temp = temp->next;

	NewNode->next = temp->next;
	temp->next = NewNode;
	NewNode->prev = temp;
}

template <typename T>
void DoublyLinkedList<T>::deleteNode(T data) {
	ListNode * temp = this->head;

	while (temp) {
		if (temp->data == data) break;
		temp = temp->next;
	}

	if (temp == nullptr) return;

	temp->prev->next = temp->next;
	delete temp;
}

template <typename T>
void DoublyLinkedList<T>::reverse() {
	ListNode * next = this->head;
	ListNode * prev = nullptr;
	

	while (this->head) {
		next = this->head->next;
		this->head->prev = this->head->next;
		this->head->next = prev;
		prev = this->head;
		this->head = next;
	}

	this->head = prev;
}

template <typename T>
void DoublyLinkedList<T>::traverse() {
	ListNode * temp = this->head;

	while (temp) {
		std::cout << temp->data << ' ';
		temp = temp->next;
	}

	std::cout << '\n';
}