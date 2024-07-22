/*
###########################################
Source: GeeksforGeeks

Problem statement:
There is BST given with the root node with the key part as an integer only. You need to find the in-order successor and predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.

Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor.

Constraints:
1 <= Number of nodes <= 10^4
1 <= key of node <= 10^7
1 <= key <= 10^7

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

struct Node {
    int data;
    Node * left;
    Node * right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* buildTree(std::string input) {
    if (input.length() == 0 || input[0] == 'N') return NULL;

    std::vector<std::string> ip;

    std::istringstream iss(input);
    for (std::string str; iss >> str;) ip.push_back(str);

    Node* root = new Node(stoi(ip[0]));

    std::queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < ip.size()) {

        Node* currNode = q.front();
        q.pop();

        std::string currVal = ip[i];

        if (currVal != "N") {

            currNode->left = new Node(stoi(currVal));

            q.push(currNode->left);
        }

        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        if (currVal != "N") {

            currNode->right = new Node(stoi(currVal));

            q.push(currNode->right);
        }
        i++;
    }

    return root;
}


class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        while (root) {
            if (root->data == key) {
                
                if (root->left) {
                    pre = root->left;
                    while (pre->right) pre = pre->right;
                }
                if (root->right) {
                    suc = root->right;
                    while (suc->left) suc = suc->left;
                }
                
                break;
            } 
            else if (root->data > key) {
                if (suc == nullptr or suc->data > root->data) suc = root;
                root = root->left;
            }
            else {
                if (pre == nullptr or pre->data < root->data) pre = root;
                root = root->right;
            }
        }
    }
};

int main() {
	std::string input = "13 8 18 0 12 17 21 N 4 10 N N N N 22 2 N N N N 25 N N 24 N N N";
    int key = 25;
    Node * root = buildTree(input);
    Node * pre = nullptr;
    Node * suc = nullptr;

    Solution obj;

    obj.findPreSuc(root, pre, suc, key);

    std::cout << (pre ? pre->data : -1) << ' ' << (suc ? suc->data : -1);
}