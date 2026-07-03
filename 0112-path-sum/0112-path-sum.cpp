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
    bool PathSum(TreeNode* node, int targetSum){
        if (node == NULL){
            return false;
        }

        targetSum -= node -> val;
        if (node -> left == NULL && node -> right == NULL){
            return targetSum == 0;
        }
        return PathSum(node -> left, targetSum) || PathSum(node -> right, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return PathSum(root, targetSum);
    }
};