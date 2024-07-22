/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:

    - The left subtree of a node contains only nodes with keys less than the node's key.
    - The right subtree of a node contains only nodes with keys greater than the node's key.
    - Both the left and right subtrees must also be binary search trees.

Constraints:
1 ≤ Number of nodes ≤ 10^5
1 ≤ Data of a node ≤ 10^5

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
    //Function to check whether a Binary Tree is BST or not.
    bool checkforBST(Node * root, int Min, int Max){
        if (root == nullptr)
            return 1;
        
        if (root->data < Min or root->data > Max)
            return 0;
        
        return checkforBST(root->left, Min, root->data - 1) and checkforBST(root->right, root->data + 1, Max);
    }
    
    bool isBST(Node* root) 
    {
        return checkforBST(root, -100001, 100001);
    }
};

int main() {
	std::string input = "13 8 18 0 12 17 21 N 4 10 N N N N 22 2 N N N N 25 N N 24 N N N";
    int key = 25;
    Node * root = buildTree(input);

    Solution obj;

    if (obj.isBST(root)) std::cout << "YES\n";
    else std::cout << "NO\n";
}