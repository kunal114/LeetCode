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
    TreeNode* inorder(TreeNode* root){
        TreeNode* curr = root;
        while(curr->left!=NULL and curr!=NULL){
            curr = curr->left;
        }
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        // base case
        if(root == NULL)
            return NULL;
        if(root -> val == key){
        // 0 child
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }
        // 1 child
            // left child
            if(root -> left != NULL && root -> right == NULL){
                TreeNode* temp = root -> left;
                delete root;
                return temp;
            }
            // right child
            if(root -> left == NULL && root -> right != NULL){
                TreeNode* temp = root -> right;
                delete root;
                return temp;
            }
            // 2 child
            if(root -> left != NULL && root -> right != NULL){
                int mini = inorder(root -> right) -> val;
                root -> val = mini;
                root -> right = deleteNode(root -> right, mini);
                return root;
            }
          }
          else if(root -> val > key){
             root -> left = deleteNode(root -> left, key);
             return root;
          }
          else{
             root -> right = deleteNode(root -> right, key);
              return root;
          }
        return root;
    }
};