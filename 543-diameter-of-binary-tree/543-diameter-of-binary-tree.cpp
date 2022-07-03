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
    int height(TreeNode* root){
        //Base
        if(root==NULL) return 0;
        return max(height(root->left),height(root->right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        //Base
        if(root==NULL) return 0;
        
        //heights
        int leftH = height(root->left);
        int rightH = height(root->right);
        int ThroughRoot = leftH+rightH;
        
        //diameters
        int leftD = diameterOfBinaryTree(root->left);
        int rightD = diameterOfBinaryTree(root->right);
        
        return max(ThroughRoot,max(leftD,rightD));
        
    }
};