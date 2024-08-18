// T(N) = O(N)
// S(N) = O(H), H = height of tree
// preorder traversal

#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class BTree {

    public:
        TreeNode* root;


        BTree() {
            cout << "Created Empty Binary Tree!" << endl;
        }


        void insertNode(int val, int pos, TreeNode* curr_node) {
            TreeNode* new_node = new TreeNode();
            new_node -> val = val;
            if (pos) {
                curr_node -> right = new_node;
            }
            else {
                curr_node -> left = new_node;
            }
        }


        void helper(TreeNode* curr_node, int level, vector<int>& leftview_nodes) {
            if (curr_node == NULL) {
                return;
            }

            if (leftview_nodes.size() == level) {
                leftview_nodes.emplace_back(curr_node -> val);
            }

            helper(curr_node -> left, level + 1, leftview_nodes);
            helper(curr_node -> right, level + 1, leftview_nodes);
        }


        vector<int> leftView(TreeNode* root_node) {

            vector<int> leftview_nodes;
            helper(root_node, 0, leftview_nodes);

            return leftview_nodes;
        }

};


int main() {

    // creating btree
    BTree bt;
    bt.root = new TreeNode();
    bt.root -> val = 1;
    bt.insertNode(2, 0, bt.root);
    bt.insertNode(4, 0, bt.root -> left);
    bt.insertNode(5, 1, bt.root -> left);
    bt.insertNode(6, 1, bt.root -> left -> right);
    bt.insertNode(3, 1, bt.root);
    cout << "finished creating test binary tree!" << endl;

    // printing morris inorder traversal
    vector<int> leftview_nodes = bt.leftView(bt.root);
    for (auto node : leftview_nodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}