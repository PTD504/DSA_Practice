// A tree data structure is a hierarchical data structure that consists of nodes connected by edges.
#include "../Stack/Stack.h"
#include "../Queue/Queue.h"

template <typename T>
class BinarySearchTree {
protected:
    struct TreeNode {
        T data;
        TreeNode * left;
        TreeNode * right;

        TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
    };

    TreeNode * root;

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        deleteTree(root);
    }

    void insert(T value);
    void remove(T value);
    TreeNode * search(T value) const;

    void inorderTraversal() {
        srand(time(NULL));
        if (rand() & 1) rInorderTraversal(root);
        else itInorderTraversal(root);

        std::cout << '\n';
    }

    void preorderTraversal() {
        srand(time(NULL));
        if (rand() & 1) rPreorderTraversal(root);
        else itPreorderTraversal(root);

        std::cout << '\n';
    }

    void postorderTraversal() {
        srand(time(NULL));
        if (rand() & 1) rPostorderTraversal(root);
        else itPostorderTraversal(root);

        std::cout << '\n';
    }

    void levelorderTraversal() {
        LevelorderTraversal(root);

        std::cout << '\n';
    }

protected:
    void rInorderTraversal(TreeNode * node) {
        if (node != nullptr) {
            rInorderTraversal(node->left);
            std::cout << node->data << ' ';
            rInorderTraversal(node->right);
        }
    }

    void itInorderTraversal(TreeNode * node) {
        Stack<TreeNode*> st;
        TreeNode * temp = node;

        while (!st.isEmpty() || temp) {
            while (temp) {
                st.push(temp);
                temp = temp->left;
            } 

            temp = st.top();
            st.pop();
            std::cout << temp->data << ' ';
            temp = temp->right;
        }
    }

    void rPreorderTraversal(TreeNode * node) {
        if (node != nullptr) {
            std::cout << node->data << ' ';
            rPreorderTraversal(node->left);
            rPreorderTraversal(node->right);
        }
    }

    void itPreorderTraversal(TreeNode * node) {
        Stack<TreeNode*> st;
        st.push(node);
        TreeNode * temp;

        while (!st.isEmpty()) {
            temp = st.top();
            st.pop();
            std::cout << temp->data << ' ';

            if (temp->right) st.push(temp->right);
            if (temp->left) st.push(temp->left);
        }
    }

    void rPostorderTraversal(TreeNode * node) {
        if (node != nullptr) {
            rPostorderTraversal(node->left);
            rPostorderTraversal(node->right);
            std::cout << node->data << ' ';
        }
    }

    void itPostorderTraversal(TreeNode * node) {
        Stack<TreeNode*> st1, st2;
        st1.push(node);
        TreeNode * temp;

        while (!st1.isEmpty()) {
            temp = st1.top();
            st1.pop();
            st2.push(temp);

            if (temp->left) st1.push(temp->left);
            if (temp->right) st1.push(temp->right);
        }

        while (!st2.isEmpty()) {
            std::cout << st2.top()->data << ' ';
            st2.pop();
        }
    }

    void deleteTree(TreeNode * node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    void LevelorderTraversal(TreeNode * node) {
        Queue<TreeNode*> q;
        q.push(node);
        TreeNode * temp;

        while (!q.isEmpty()) {
            int sz = q.size();

            while (sz--) {
                temp = q.front();
                q.pop();
                std::cout << temp->data << ' ';

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }
    }
};

template <typename T>
typename BinarySearchTree<T>::TreeNode * BinarySearchTree<T>::search(T value) const {
    TreeNode * node = this->root;

    if (node == nullptr) return nullptr;

    while (node) {
        if (node->data == value) return node;
        else if (node->data > value) node = node->left;
        else node = node->right;
    }

    return nullptr;
}

template <typename T>
void BinarySearchTree<T>::insert(T value) {
    if (this->search(value)) return;
    if (this->root == nullptr) {
        this->root = new TreeNode(value);
        return;
    }

    TreeNode * temp = this->root;
    TreeNode * prev = nullptr;

    while (temp) {
        prev = temp;
        if (temp->data > value) temp = temp->left;
        else temp = temp->right;
    }

    if (prev->data > value) prev->left = new TreeNode(value);
    else prev->right = new TreeNode(value);
}

template <typename T>
void BinarySearchTree<T>::remove(T value) {
    TreeNode* parent = nullptr;
    TreeNode* node = root;

    while (node && node->data != value) {
        parent = node;
        if (value < node->data)
            node = node->left;
        else
            node = node->right;
    }

    if (node == nullptr) return;

    if (node->left && node->right) {
        TreeNode* successorParent = node;
        TreeNode* successor = node->right;

        while (successor->left) {
            successorParent = successor;
            successor = successor->left;
        }

        node->data = successor->data;

        node = successor;
        parent = successorParent;
    }

    TreeNode* child = (node->left) ? node->left : node->right;

    if (parent == nullptr) {
        root = child;
    } else {
        if (parent->left == node)
            parent->left = child;
        else
            parent->right = child;
    }

    delete node;
}


