/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given a Binary Tree, complete the function to populate the next pointer for all nodes. The next pointer for every node should point to the Inorder successor of the node.
You do not have to return or print anything. Just make changes in the root node given to you.

Note: The node having no in-order successor will be pointed to -1. You don't have to add -1 explicitly, the driver code will take care of this.

Constraints:
1<= no. of nodes <=10^5
1<= data of the node <=10^5

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <sstream>

struct Node {
    int data;
    Node * left;
    Node * right;
    Node * next;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
        next = nullptr;
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

    void populateNext(Node *root) {
        
        std::stack<Node*> s;
        Node* temp = root;
        Node* prev = nullptr;
        
        while (!s.empty() or temp) {
            while (temp) {
                s.push(temp);
                temp = temp->left;
            }
            
            temp = s.top();
            s.pop();
            
            if (prev != nullptr) prev->next = temp;
            
            prev = temp;
            temp = temp->right;
        }
    }
};

int main() {
	std::string input = "13 8 18 0 12 17 21 N 4 10 N N N N 22 2 N N N N 25 N N 24 N N N";
    int key = 25;
    Node * root = buildTree(input);

    Solution obj;

    obj.populateNext(root);

    while (root->left) root = root->left;

    while (root) {
        std::cout << root->data << "->" << (root->next ? root->next->data : -1) << ' ';
        root = root->next;
    }
}