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
    void paths(TreeNode* node, int target, vector<vector<int>>& ans, vector<int>& curr) {
        if (node == NULL) return;

        target -= node -> val;
        
        curr.push_back(node -> val);

        if (node -> left == NULL && node -> right == NULL && target == 0) {
            ans.push_back(curr);
        }
        
        paths(node -> left, target, ans, curr);
        paths(node -> right, target, ans, curr);
        curr.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> curr;
        paths(root, targetSum, ans, curr);
        return ans;
    }
};