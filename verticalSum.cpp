/*
Given a binary tree having n nodes, find the vertical sum of the nodes that are in the same vertical line. Return all sums through different vertical lines starting from the left-most vertical line to the right-most vertical line.

Examples:

Input:

  
Output: 
4 2 12 3 7
Explanation:

The tree has 5 vertical lines
Line 1 has only one node 4 => vertical sum is 4.
Line 2 has only one node 2 => vertical sum is 2.
Line-3 has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12.
Line-4 has only one node 3 => vertical sum is 3.
Line-5 has only one node 7 => vertical sum is 7.
Input:

Output: 
7 6 4 3 2 1
Explanation:
There are six vertical lines each having one node.
Constraints:
1<=n<=104
1<= Node value <= 105
using doubly linked list : TC:O(n) SC:O(n)

*/
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
struct DLLNode {
    int data;
    DLLNode *prev, *next;
    DLLNode(int val) {
        data = val;
        prev = next = NULL;
    }
};
void verticalSumUtil(Node* root, DLLNode* curr) {
    if (root == NULL) return;
    curr->data += root->data;
    if (root->left) {
        if (curr->prev == NULL) {
            curr->prev = new DLLNode(0);
            curr->prev->next = curr;
        }
        verticalSumUtil(root->left, curr->prev);
    }
    if (root->right) {
        if (curr->next == NULL) {
            curr->next = new DLLNode(0);
            curr->next->prev = curr;
        }
        verticalSumUtil(root->right, curr->next);
    }
}
vector<int> verticalSum(Node *root) {
    if (root == NULL) return {};
    DLLNode* head = new DLLNode(0);
    verticalSumUtil(root, head);
    while (head->prev) {
        head = head->prev;
    }
    vector<int> res;
    while (head) {
        res.push_back(head->data);
        head = head->next;
    }
    return res;
}
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> res = verticalSum(root);
    for (int x : res) {
        cout << x << " ";
    }
    return 0;
}