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
    int index;
    void set_index(int ind){
        index = ind;
    }
    int find(vector<int> inorder, int start,int end , int curr){
        for(int i=start;i<=end;i++){
            if(curr==inorder[i]) return i;
        }
        return -1;
    }
    TreeNode* build(vector<int> &inorder,vector<int> &postorder, int start,int end){
        if(start>end) return NULL;
        
        int curr = postorder[index];
        index--;
        TreeNode* temp = new TreeNode(curr);
        
        if(start==end) return temp;

        int pos = find(inorder,start,end,curr);
        temp->right = build(inorder,postorder,pos+1,end);
        temp->left = build(inorder,postorder,start,pos-1);
        
        return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        set_index(postorder.size()-1);
        return build(inorder,postorder,0,inorder.size()-1);
    }
};