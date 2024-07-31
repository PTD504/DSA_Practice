/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given a binary tree. Find the size of its largest subtree which is a Binary Search Tree.
Note: Here Size equals the number of nodes in the subtree.

Constraints:
1 ≤ Number of nodes ≤ 10^5
1 ≤ Data of a node ≤ 10^6

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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


class Solution{
    public:
    
    int ans = 1;
    
    struct info {
        int mx, mn, _size;
        bool isBST;
        
        info(int M = 1e9, int m = 0, int s = 0, bool isBst = true) {
            mx = M;
            mn = m;
            _size = s;
            isBST = isBst;
        }
    };
    
    info findSubBST(Node * root) {
        if (!root->left and !root->right) return info(root->data, root->data, 1, true);
        
        info left(0), right(0, 1e9);
        
        if (root->left) left = findSubBST(root->left);
        if (root->right) right = findSubBST(root->right);
        
        bool bCur = root->data > left.mx and root->data < right.mn;
        
        if (left.isBST and right.isBST and bCur) {
            ans = std::max(ans, left._size + right._size + 1);
        }
        
        if (!root->left) 
            return info(std::max(root->data, right.mx), std::min(root->data, right.mn), right._size + 1, bCur & right.isBST);
        else if (!root->right)
            return info(std::max(root->data, left.mx), std::min(root->data, left.mn), left._size + 1, bCur & left.isBST);
        else
            return info(std::max({root->data, left.mx, right.mx}), std::min({root->data, left.mn, right.mn}), left._size + right._size + 1, left.isBST & right.isBST & bCur);
    }
    
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	auto _ = findSubBST(root);
    	return ans;
    }
};

int main() {
	std::string input = "4787 2088 4563 3580 2848 1796 1544 2987 N 504 118 4328 4692 4455 3683 1454 3753 N 2357 971 4814 4325 1275 2769 1243 3427 N 5014 2257 2133 764 4528 1628 2183 4578 N 4007 2009 3129 2119 3805 4964 77 4600 N 53 4697 4555 4799 3351 981 3524 971 N 2243 3601 559 3517 1633 1801 2208 1619 N 4349 4340 2382 3848 1231 4856 3689 501 N 1837 2082 2619 905 2309 2988 476 2654 N 2656 294 2424 1270 1274 1211 2240 3809 N 4812 2798 2589 1708 4598 4796 3326 3918 N 4399 971 3029 601 799 1981 1394 2635 N 4062 4012 3831 1343 1971 4598 4288 4626 N 4891 1683 1159 1429 2894 3398 209 2969 N 1167 2797 4676 1028 2565 2974 209 1935 N 4236 3529 2828 6 482 4513 2932 4835 N 3496 1734 1441 731 1303 700 328 1166 N 2383 1487 2594 540 148 3094 3508 1315 N 862 3447 2634 3718 1684 2843 917 892 N 1343 4036 897 1824 3520 4121 1631 1987 N 826 3363 2717 2421 4063 3337 3878 1709 N 87 1735 2248 526 4828 1019 1840 661 N 4757 4474 4379 1413 2580 559 2596 3922 N 4594 3784 718 3085 2876 2640 335 3702 N 1266 3344 1386 300 1652 235 2008 2030 N 1969 4547 2555 1768 829 4687 2720 558 N 4424 2362 2262 1975 2920 4857 1160 2485 N 3612 2169 833 1460 4808 1168 425 1046 N 4511 2102 1637 1426 2336 3937 3747 4596 N 3455 1565 1627 4576 1515 4346 397 910 N 1972 2658 3176 4891 2778 4336 2640 1361 N 1476 3472 3112 1548 4931 3828 2885 4705 N 901 4521 1102 3236 3429 112 2803 2148 N 1677 4429 1987 3191 4039 2383 4393 982 N 12 2540 1136 2789 2139 3775 4441 3615 N 2511 2525 426 2705 1324 3310 2382 2225 N 3094 3483 724 1787 3887 3819 4226 535 N 3219 1184 3725 2521 3566 3089 3502 3869 N 893 4638 1629 3031 3676 1333 1909 1158 N 3857 2334 3863 445 907 1508 2961 4001 N 254 3684 1051 4140 2474 248 4674 957 N 1431 3663 3477 4996 1723 2243 3836 2907 N 1852 728 910 791 2352 2818 2241 1181 N 416 1367 1917 1322 2874 4877 586 3127 N 3824 1636 2239 1562 1883 1884 2518 3313 N 810 1258 3572 2533 3500 2671 411 615 N 3690 1612 1406 1014 4722 3646 2486 109 N 5012 4402 1430 2857 4542 2308 1247 3337 N 3943 3485 4898 798 633 2679 4402 1442 N 3937 2946 4266 2408 880 4969 3023 4570 N 1552 4428 555 1245 3337 3040 1645 3320 N 2705 3367 1440 2218 646 2686 818 4588 N 1143 980 649 2067 3950 23 3800 2858 N 3260 3038 530 4139 3270 3844 3680 4821 N 3243 4526 1330 1843 2537 3266 134 505 N 1604 1573 3014 2541 4550 3832 2101 956 N 75 3041 3022 4024 3355 1794 2146 1586 N 95 2675 989 3364 1490 4668 3156 5024 N 4458 4777 2130 1966 3015 2263 2763 4910 N 4127 748 2423 3648 4871 4815 4604 4945 N 2827 2889 4233 1446 4682 1642 3031 4776 N 4608 4019 3111 1361 3951 1531 1648 3672 N 1571 3777 901 4877 1011 3663 23 401 N 4411 2445 4340 4253 2523 4207 4462 613 N 2068 3958 2058 2013 571 353 2053 150 N 4663 427 1802 3877 1957 3449 2520 3820 N 2197 3421 3960 3499 2055 3982 4191 1437 N 1690 3502 954 4212 2973 387 89 12 N 4636 2146 2024 178 2498 4368 619 2425 N 4795 2420 1273 2015 1132 3793 806 3620 N 2185 30 2090 4531 4011 1544 1232 673 N 17 2185 148 2989 2863 236 3292 2470 N 2674 580 2647 435 4947 3557 2859 4713 N 1240 4132 1700 2371 3188 2797 1254 636 N 2826 3343 138 2101 4886 1369 3065 166 N 3845 3212 3447 1679 3740 1710 4148 1385 N 2581 2058 1819 2500 878 4678 2476 2117 N 4073 4467 4779 2232 2528 1004 2867 617 N 4638 3296 2717 4787 4665 753 4953 3481 N 3965 3663 424 2968 636 4571 4352 3217 N 1893 1142 980 2770 1083 3747 151 127 N 3478 193 2650 977 1489 488 1593 1098 N 3784 4310 1149 3712 326 1365 2456 4582 N 5027 2879 2521 926 2714 1844 4434 4606 N 3278 385 2639 4360 4424 3081 4779 2873 N 3274 2400 4141 26 3180 705 1123 2227 N 278 2563 910 604";
    Node * root = buildTree(input);

    Solution obj;

    std::cout << obj.largestBst(root);
}