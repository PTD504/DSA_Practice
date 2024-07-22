/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given the root of a Binary Search Tree. The task is to find the minimum valued element in this given BST.

Constraints:
0 <= n <= 10^4

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


class Solution {
  public:
    int minValue(Node* root) {
        if (root == nullptr) return -1;
        int mn = 1e4 + 1;
        
        while (root) mn = root->data, root = root->left;
        
        return mn;
    }
};

int main() {
	std::string input = "5 4 6 3 N N 7 1";
    Node * root = buildTree(input);

    Solution obj;

    std::cout << obj.minValue(root);
}