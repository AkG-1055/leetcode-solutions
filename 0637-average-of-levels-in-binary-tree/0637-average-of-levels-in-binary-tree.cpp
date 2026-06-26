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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                if (node -> left != NULL) q.push(node -> left);
                if (node -> right != NULL) q.push(node -> right);
                level.push_back(node -> val);
            }
            res.push_back(level);
        }
        vector<double> ans;
        for (int i = 0; i < res.size(); i++){
            double avg = 0;
            double sum = 0;
            for (int j = 0; j < res[i].size(); j++){
                sum += res[i][j];
            }
            avg = sum / res[i].size();
            ans.push_back(avg);
        }
        return ans;
    }
};