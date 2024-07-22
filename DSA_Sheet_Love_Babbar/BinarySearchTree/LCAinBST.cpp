/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given a Binary Search Tree (with all values unique) and two node values n1 and n2 (n1!=n2). Find the Lowest Common Ancestors of the two nodes in the BST.

Constraints:
1 <= N <= 10^4

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

#define min(a, b) (a < b ? a : b)

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


class Solution{
public:
    Node* LCA(Node *root, int n1, int n2)
    {
        if (root->data == n1 or root->data == n2)
            return root;
        else if ((root->data > n1 and root->data < n2) or (root->data > n2 and root->data < n1))
            return root;
        else if (root->data < min(n1, n2))
            return LCA(root->right, n1, n2);
        else
            return LCA(root->left, n1, n2);
    }
};

int main() {
	std::string input = "13 8 18 0 12 17 21 N 4 10 N N N N 22 2 N N N N 25 N N 24 N N N";
    int n1 = 25, n2 = 8;
    Node * root = buildTree(input);

    Solution obj;

    Node * lca = obj.LCA(root, n1, n2);

    std::cout << lca->data;
}