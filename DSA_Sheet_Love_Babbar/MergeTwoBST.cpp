/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given two BSTs, return elements of merged BSTs in sorted form.

Constraints:
1 ≤ Number of Nodes ≤ 10^5

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
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    
    std::vector<int> merge(Node *root1, Node *root2) {
        std::vector<int> ans;
        std::stack<Node*> s1, s2;

        while (!s1.empty() or root1 or !s2.empty() or root2) {
            while (root1) s1.push(root1), root1 = root1->left;
            while (root2) s2.push(root2), root2 = root2->left;

            if (s1.empty()) {
                root2 = s2.top();
                s2.pop();
                ans.push_back(root2->data);
                root2 = root2->right;
            }
            else if (s2.empty()) {
                root1 = s1.top();
                s1.pop();
                ans.push_back(root1->data);
                root1 = root1->right;
            }
            else 
            {    
                root1 = s1.top(), root2 = s2.top();

                if (root1->data > root2->data) {
                    ans.push_back(root2->data);
                    s2.pop();
                    root1 = nullptr, root2 = root2->right;
                }
                else {
                    ans.push_back(root1->data);
                    s1.pop();
                    root2 = nullptr, root1 = root1->right;
                }
            }
        }

        return ans;
    }
};

int main() {
	std::string input1 = "13 8 18 0 12 17 21 N 4 10 N N N N 22 2 N N N N 25 N N 24 N N N";
    std::string input2 = "7 5 12 3 6 8 14 N N N N N 11 13 100";

    Node* root1 = buildTree(input1);
    Node* root2 = buildTree(input2);

    Solution obj;

    for (int i : obj.merge(root1, root2)) std::cout << i << ' ';
}