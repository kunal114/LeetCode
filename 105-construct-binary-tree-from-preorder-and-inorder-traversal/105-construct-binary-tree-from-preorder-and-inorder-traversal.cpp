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
    int index = 0;//for preorder
    int find(vector<int> in,int st,int end,int curr){
        for(int i=st;i<=end;i++){
            if(in[i]==curr)
                return i;
        }
        return -1;
    }
    TreeNode* build(vector<int> &preorder, vector<int> &inorder, int start,int end){
        //start and end pointers for inorder vector
        
        //base condition
        if(start>end){
            return NULL;
        }
        
        int curr = preorder[index];
        index++;
        TreeNode* temp = new TreeNode(curr);//to build tree(nodes)
        
        //if no left and right for a node exists
        if(start==end){
            return temp;
        }
        
        int pos = find(inorder, start, end, curr);
        temp->left = build(preorder,inorder,start,pos-1);
        temp->right = build(preorder,inorder,pos+1,end);
        
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,inorder,0,inorder.size()-1);
    }
};