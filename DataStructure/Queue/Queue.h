// A queue is a linear data structure that follows the First In, First Out (FIFO) principle. 
// This means that the first element added to the queue will be the first one to be removed.
#include <stdexcept>

const int MAX_QUEUE_SIZE = 1e5;

template <typename T>
class Queue 
{
private:
	T container[MAX_QUEUE_SIZE];
	int first, last;

public:
	Queue() {
		this->first = 0;
		this->last = 0;
	}

	void push(T);
	void pop();
	T front() const;
	size_t size() const;
	bool isEmpty() const;
};

template <typename T>
void Queue<T>::push(T element) {
	if (this->last >= MAX_QUEUE_SIZE) {
		throw std::overflow_error("Queue overflow. Cannot push new element.");
	}

	this->container[last] = element;
	last++;
}

template <typename T>
void Queue<T>::pop() {
	if (this->first >= this->last) {
		throw std::out_of_range("Queue is empty. Cannot pop.");
	}

	first++;
}

template <typename T>
T Queue<T>::front() const {
	if (this->first >= this->last) {
		throw std::out_of_range("Queue is empty. Cannot retrieve top element.");
	}

	return this->container[first];
}

template <typename T>
size_t Queue<T>::size() const {
	return size_t(this->last - this->first); 
}

template <typename T>
bool Queue<T>::isEmpty() const {
	return this->first >= this->last;
}