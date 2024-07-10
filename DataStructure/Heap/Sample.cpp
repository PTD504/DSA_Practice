#include <iostream>
#include "Heap.h"

int main() {
    MinHeap<int> mh;
    mh.insert(67);
    mh.insert(56);
    mh.insert(100);
    
    while (!mh.isEmpty()) {
        std::cout << mh.pop() << ' ';
    }
}