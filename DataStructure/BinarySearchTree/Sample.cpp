#include <iostream>
#include "BST.h"

int main() {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(2);
    bst.insert(7);

    std::cout << "Binary Search Tree - Inorder Traversal: ";
    bst.inorderTraversal();
    
    bst.remove(15);
    std::cout << "Binary Search Tree - Postorder Traversal: ";
    bst.postorderTraversal();
    
    std::cout << "Binary Search Tree - Levelorder Traversal: ";
    bst.levelorderTraversal();

    return 0;
}