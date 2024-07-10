// A heap is a specialized tree-based data structure that satisfies the heap property:
// in a min-heap, the parent node is always smaller than or equal to its children 
// in a max-heap, the parent node is always greater than or equal to its children.

#include <vector>
#include <stdexcept>

template <typename T>
class Heap 
{
protected:
	std::vector<T> container;  
    int _size;
    int capacity;  

public:

    Heap(int capacity = 0) {
        _size = 0;
        this->capacity = capacity;
        container.resize(capacity);
    }
    // Function to heapify the node at index idx
    virtual void heapify(int) = 0;

    // Function to build a max heap from a given array arr
    void buildHeap(const std::vector<T>&);

    // Insert new element into Heap
    virtual void insert(T) = 0;

    // Get the value of the root node
    T top();

    // Return the value of the root node and remove it from the heap
    T pop();

    bool isEmpty() {
        return _size <= 0;
    }
};

template <typename T>
void Heap<T>::buildHeap(const std::vector<T>& arr) {
    capacity = arr.size();
    _size = capacity;
    container = arr;

    // rearrange array
    for (int idx = (_size - 1) >> 1; idx >= 0; --idx) {
        heapify(idx);
    }
}

template <typename T>
T Heap<T>::top() {
    if (_size <= 0)
        throw std::out_of_range("The Heap is empty. Cannot retrieve top element.");

    return container[0];
}

template <typename T>
T Heap<T>::pop() {
    if (_size <= 0)
        throw std::out_of_range("The Heap is empty. Cannot pop.");
    if (_size == 1) {
        _size--;
        return container[0];
    }

    T root = container[0];
    container[0] = container[_size - 1];
    _size--;
    // Heapify the root node
    heapify(0);  
    return root;
}

template <typename T>
class MaxHeap: public Heap<T>
{
public:
    MaxHeap(int capacity = 0): Heap<T>(Heap<T>::capacity) {}

    void heapify(int idx) override {
        int mx = idx, left = (mx << 1) + 1, right = (mx << 1) + 2;

	    if (left < Heap<T>::_size and Heap<T>::container[left] > Heap<T>::container[mx]) mx = left;
	    if (right < Heap<T>::_size and Heap<T>::container[right] > Heap<T>::container[mx]) mx = right;

	    if (mx != idx) {
		    std::swap(Heap<T>::container[mx], Heap<T>::container[idx]);
		    heapify(mx);
	    }
    }

    void insert(T value) override {
        if (Heap<T>::_size >= Heap<T>::capacity) {
            // Resize the heap
            if (Heap<T>::capacity == 0) Heap<T>::capacity = 1;
            else Heap<T>::capacity *= 2;
            Heap<T>::container.resize(Heap<T>::capacity);
        }

        Heap<T>::_size++;
        int i = Heap<T>::_size - 1;
        Heap<T>::container[i] = value;

        // Handling violation
        while (i != 0 && Heap<T>::container[(i - 1) >> 1] < Heap<T>::container[i]) {
            std::swap(Heap<T>::container[i], Heap<T>::container[(i - 1) >> 1]);
            i = (i - 1) >> 1;
        }
    }
};

template <typename T>
class MinHeap: public Heap<T> 
{
public:
    MinHeap(int capacity = 0): Heap<T>(Heap<T>::capacity) {}  
    
    void heapify(int idx) override {
        int mx = idx, left = (mx << 1) + 1, right = (mx << 1) + 2;

	    if (left < Heap<T>::_size and Heap<T>::container[left] < Heap<T>::container[mx]) mx = left;
	    if (right < Heap<T>::_size and Heap<T>::container[right] < Heap<T>::container[mx]) mx = right;

	    if (mx != idx) {
		    std::swap(Heap<T>::container[mx], Heap<T>::container[idx]);
		    heapify(mx);
	    }
    }

    void insert(T value) override {
        if (Heap<T>::_size >= Heap<T>::capacity) {
            // Resize the heap
            if (Heap<T>::capacity == 0) Heap<T>::capacity = 1;
            else Heap<T>::capacity *= 2;
            Heap<T>::container.resize(Heap<T>::capacity);
        }

        Heap<T>::_size++;
        int i = Heap<T>::_size - 1;
        Heap<T>::container[i] = value;

        // Handling violation
        while (i != 0 && Heap<T>::container[(i - 1) >> 1] > Heap<T>::container[i]) {
            std::swap(Heap<T>::container[i], Heap<T>::container[(i - 1) >> 1]);
            i = (i - 1) >> 1;
        }
    }
};