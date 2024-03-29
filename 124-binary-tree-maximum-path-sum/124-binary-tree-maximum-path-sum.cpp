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
    int dp(TreeNode* root,int &res){
        if(root==NULL) return 0;
        
        int l = dp(root->left,res);
        int r = dp(root->right,res);
        
        int temp = max(max(l,r)+root->val, root->val);
        int ans = max(temp, l+r+root->val);
        res = max(res,ans);
        
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dp(root,res);
        return res;
    }
};