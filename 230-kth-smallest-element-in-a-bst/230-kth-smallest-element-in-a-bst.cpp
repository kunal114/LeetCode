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
    void morris(TreeNode* root,int k,vector<int> &ans){
        if(root==NULL) return;
        while(root){
            if(root->left==NULL){
                ans.push_back(root->val);
                root=root->right;
            }
            else{
                //find inorder predecessor
                TreeNode *curr = root->left;
                while(curr->right && curr->right!=root){
                    curr=curr->right;
                }
                
                //if predecessor already points to root, it means its already visited
                if(curr->right==root){
                    curr->right=NULL;
                    ans.push_back(root->val);
                    root=root->right;
                }//else traverse the left subtree of root
                else{
                    curr->right = root;
                    root=root->left;
                    
                }
            }
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        morris(root,k,ans);
        return ans[k-1];
    }
};