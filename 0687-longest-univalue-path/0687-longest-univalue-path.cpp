/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int length = 0;
        longestPath(root, length);
        return length;
    }
private:
    int longestPath(TreeNode* node, int& length){
        if (node == NULL) return 0;

        int lh = longestPath(node -> left, length);
        int rh = longestPath(node -> right, length);

        if (node -> left != NULL && node -> left -> val != node -> val) {
            lh = 0;
        }
        if (node -> right != NULL && node -> right -> val != node -> val) {
            rh = 0;
        }

        length = max(length, lh + rh);

        return max(lh, rh) + 1;
    }
};