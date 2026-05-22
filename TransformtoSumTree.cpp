/*
Given a root of a binary tree with n nodes, where each node may contain positive or negative values, convert it into a tree such that each node’s new value is equal to the sum of all values in its left and right subtrees (based on the original tree). For leaf nodes, update their values to 0.

Examples:      

Input: root = [10, -2, 6, 8, -4, 7, 5]

 
Output:
            

Explanation:
Leaf nodes update: The leaf nodes 8, -4, 7, 5 are changed to 0 since they have no children.
Update internal nodes: Left child: 8 + (-4) = 4
Right child: 7 + 5 = 12
Update root node: Root = sum of left and right subtree values = 4 + 12 = 20

Constraints:
1 ≤ n ≤ 104
TC : O(n) SC:O(n)
GFG - POTD 407, 23rd may 2026
*/
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
class Solution {
public:
    int solve(Node* root) {
        if (root == NULL)
            return 0;
        int leftSum = solve(root->left);
        int rightSum = solve(root->right);
        int oldValue = root->data;
        root->data = leftSum + rightSum;
        return oldValue + leftSum + rightSum;
    }
    void toSumTree(Node* root) {
        solve(root);
    }
};
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main() {

    /*
            10
           /  \
         -2    6
         / \   / \
        8 -4  7  5
    */
    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);
    Solution obj;
    obj.toSumTree(root);
    cout << "Inorder Traversal of Sum Tree:\n";
    inorder(root);
    return 0;
}