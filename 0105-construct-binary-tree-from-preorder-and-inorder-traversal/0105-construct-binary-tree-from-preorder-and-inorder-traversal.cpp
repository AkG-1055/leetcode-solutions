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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap;

        for (int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, 
                                   inorder, 0, inorder.size() - 1, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, int PreStart, int PreEnd,
                        vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMap){
        
        if(PreStart > PreEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[PreStart]);

        int inRoot = inMap[root -> val];
        int numsleft = inRoot - inStart;

        root -> left = buildTree(preorder, PreStart + 1, PreStart + numsleft, 
                                inorder, inStart, inRoot - 1, inMap);

        root -> right = buildTree(preorder, PreStart + numsleft + 1, PreEnd, 
                                inorder, inRoot + 1, inEnd, inMap);

        return root;
    }
};