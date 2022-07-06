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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
private:
    int height(TreeNode* node, int& diameter) {
        //Base
        if (!node) {
            return 0;
        }
        //Hypothesis
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);
        //Induction
        int temp = max(lh,rh)+1;
        int ans = lh+rh;
        diameter = max(diameter,ans);
        
        return temp;
    }
};