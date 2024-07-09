// A stack is a linear data structure that follows the Last In, First Out (LIFO) principle. 
// This means that the last element added to the stack is the first one to be removed.
#include <stdexcept>

const int MAX_SIZE_STACK = 1e5;

template <typename T>
class Stack 
{
private:
	T container[MAX_SIZE_STACK];
	int it_top;

public:
	Stack() {
		this->it_top = 0;
	}

	void push(T);
	void pop();
	T top() const;
	bool isEmpty() const;
};

template <typename T>
void Stack<T>::push(T element) {
	if (this->it_top >= MAX_SIZE_STACK) {
		throw std::overflow_error("Stack overflow. Cannot push new element.");
	}

	this->container[this->it_top] = element;
	this->it_top++;
} 

template <typename T>
void Stack<T>::pop() {
	if (this->it_top <= 0) {
		throw std::out_of_range("Stack is empty. Cannot pop.");
	}

	this->it_top--;
}

template <typename T>
T Stack<T>::top() const {
	if (this->it_top <= 0) {
		throw std::out_of_range("Stack is empty. Cannot retrieve top element.");
	}

	return this->container[this->it_top - 1];
}

template <typename T>
bool Stack<T>::isEmpty() const {
	return this->it_top <= 0;
}