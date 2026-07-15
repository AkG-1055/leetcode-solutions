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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<vector<TreeNode*>> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int size = q.size();
            vector<TreeNode*> level;
            for (int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                if (node -> left != NULL) q.push(node -> left);
                if (node -> right != NULL) q.push(node -> right);
                level.push_back(node);
            }
            res.push_back(level);
        }

        for (int i = 0; i < res.size(); i++){
            if (i % 2 != 0) {
                int l = 0;
                int r = res[i].size() - 1;

                while (l < r){
                    swap(res[i][l] -> val, res[i][r] ->  val);
                    l++;
                    r--;
                }
            }
        }

        return root;
    }
};