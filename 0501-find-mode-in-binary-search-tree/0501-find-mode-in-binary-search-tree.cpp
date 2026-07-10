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
    void inOrder(TreeNode* root, vector<int>& inorder){
        if (root == NULL){
            return;
        }
        inOrder(root -> left, inorder);
        inorder.push_back(root -> val);
        inOrder(root -> right, inorder);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> inorder;
        vector<int> res;
        unordered_map<int, int> freq;

        inOrder(root, inorder);

        for (int x : inorder)
            freq[x]++;

        int max_freq = 0;

        for (auto &[value, count] : freq){
            if (count > max_freq) {
                res.clear();
                res.push_back(value);
                max_freq = count;
            }
            else if (count == max_freq) {
                res.push_back(value);
            }
            else{
                continue;
            }
        }
        return res;
    }
};