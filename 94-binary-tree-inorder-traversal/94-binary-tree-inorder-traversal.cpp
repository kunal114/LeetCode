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
    void inorder(TreeNode* root,vector<int> &ans){
        if(root == NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    void morris(TreeNode* root,vector<int> &ans){
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
    vector<int> inorderTraversal(TreeNode* root) {
        //if we are stack(push right node first then left)
        vector<int> ans;
        // inorder(root, ans);
        morris(root,ans);
        return ans;
    }
};