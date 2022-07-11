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
    void rhs(TreeNode* root,vector<int> &ans){
        if(root==NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int k = q.size();
            for(int i=1;i<=k;i++){
                TreeNode *curr = q.front();
                q.pop();
                if(i==k){
                    ans.push_back(curr->val);
                }
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rhs(root,ans);
        return ans;
    }
};