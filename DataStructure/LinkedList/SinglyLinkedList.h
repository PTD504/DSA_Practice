// Singly Linked List: Each node poTs to the next node, and the last node poTs to null.

template <typename T>
class SinglyLinkedList
{
private:
	struct ListNode 
	{
		T data;
		struct ListNode * next;

		ListNode(T val) {
			data = val;
			next = nullptr;
		}
	};

private:
	struct ListNode * head;

public:
	
	SinglyLinkedList() {
		head = nullptr;
	}

	void push_front(T);
	void push_back(T);
	void push_after(T, T);
	void deleteNode(T);
	void reverse();
	void traverse();

	~SinglyLinkedList() {
    ListNode * current = head;
    while (current != nullptr) {
        ListNode * temp = current;
        current = current->next;
        delete temp;
    }
}
};

// Insert a new node at the head of the linked list.
template <typename T>
void SinglyLinkedList<T>::push_front(T data) {
	if (this->head == nullptr) {
		this->head = new ListNode(data);
		return;
	}

	ListNode * node = new ListNode(data);
	node->next = this->head;
	this->head = node;
}

// Insert a new node at the end of the linked list.	
template <typename T>
void SinglyLinkedList<T>::push_back(T data) {
	if (this->head == nullptr) {
		this->head = new ListNode(data);
		return;
	}

	ListNode * node = head;
	ListNode * NewNode = new ListNode(data);

	while (node->next) node = node->next; 

	node->next = NewNode;
}

// Insert a new node after a specific node in the linked list.
// Assuming that the linked list contains a ListNode with data equal to the value node.
template <typename T>
void SinglyLinkedList<T>::push_after(T node, T data) {
	if (this->head == nullptr) {
		std::cout << "The ListNode with value " << node << " does not exist in the linked list\n";
		return;
	}

	ListNode * temp = this->head;
	
	while (temp->data != node) temp = temp->next;

	ListNode * NewNode = new ListNode(data);

	NewNode->next = temp->next;
	temp->next = NewNode;
}

// Delete node from linked list
template <typename T>
void SinglyLinkedList<T>::deleteNode(T data) {
	if (this->head == nullptr) return;

	ListNode * cur = head, *prev = nullptr;

	while (cur) {
		if (cur->data == data) break;
		if (prev == nullptr) prev = cur;
		else prev = prev->next;

		cur = cur->next;
	}

	if (cur == nullptr) return;
	prev->next = cur->next;
	delete cur;
}

// Reverse the linked list 
template <typename T>
void SinglyLinkedList<T>::reverse() {
	ListNode * next = this->head;
	ListNode * prev = nullptr;

	while (this->head) {
		next = this->head->next;
		this->head->next = prev;
		prev = this->head;
		this->head = next;
	}

	this->head = prev;
}

template <typename T>
void SinglyLinkedList<T>::traverse() {
	ListNode * temp = this->head;

	while (temp) {
		std::cout << temp->data << ' ';
		temp = temp->next;
	}
}