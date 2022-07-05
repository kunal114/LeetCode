/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void subtree(TreeNode* target, int k, vector<int> &ans){
        if(k<0 || target==NULL) return;
        if(k==0){
            ans.push_back(target->val);
        }
        subtree(target->left, k-1, ans);
        subtree(target->right,k-1, ans);
    }
    //int return type is for distance of target node from its ancestor
    int ancestor(TreeNode* root,TreeNode* target, int k, vector<int> &ans){
        //target not found
        if(root==NULL) return -1;
        
        //Case1: subtree check
        if(root==target){
            subtree(target,k,ans);
            return 0;//root==target(dis=0)
        }
        
        //Case2: ancestor check
        int disLeft = ancestor(root->left,target,k,ans);
        if(disLeft!=-1){
            if(disLeft+1==k){
                ans.push_back(root->val);
            }
            else{
                subtree(root->right,k-disLeft-2,ans);
            }
            return disLeft+1;
        }
        
        int disRight = ancestor(root->right,target,k,ans);
        if(disRight!=-1){
            if(disRight+1==k){
                ans.push_back(root->val);
            }
            else{
                subtree(root->left,k-disRight-2,ans);
            }
            return disRight+1;
            
        }
        
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        ancestor(root,target,k,ans);
        return ans;
    }
};