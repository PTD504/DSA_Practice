#include <iostream>
#include "DoublyLinkedList.h"

int main() {
	DoublyLinkedList<char> dlist;

	dlist.push_back('a');
	dlist.push_back('Z');
	dlist.push_back(48);
	dlist.push_front(97);

	dlist.traverse();

	dlist.push_after(48, '!');

	dlist.reverse();

	dlist.traverse();
}