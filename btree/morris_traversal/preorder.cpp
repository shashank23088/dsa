// T(N) = O(N)
// S(N) = O(1)

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


        void morrisPreorderTraversal(TreeNode* curr_node) {

            while (curr_node != NULL) {
                if (curr_node -> left == NULL) {
                    cout << curr_node -> val << " -> ";
                    curr_node = curr_node -> right;
                }

                else {
                    TreeNode* temp_node = curr_node -> left;
                    while (temp_node -> right != NULL && temp_node -> right != curr_node) {
                        temp_node = temp_node -> right;
                    }

                    if (temp_node -> right == NULL) {
                        temp_node -> right = curr_node;
                        cout << curr_node -> val << " -> ";
                        curr_node = curr_node -> left;
                    }

                    else {
                        temp_node -> right = NULL;
                        curr_node = curr_node -> right;
                    }

                }
            }

            cout << " X " << endl;

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
    bt.morrisPreorderTraversal(bt.root);

    return 0;
}