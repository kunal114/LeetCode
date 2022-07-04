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
    void levelorder(TreeNode* node,vector<vector<int>> &ans){
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> nodes;
        
        if(node==NULL) return;
        q.push({node,{0,0}});
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* curr = p.first;
            int line = p.second.first;
            int level = p.second.second;
            nodes[line][level].insert(curr->val);
            if(curr->left){
                q.push({curr->left,{line-1,level+1}});
            }
            if(curr->right){
                q.push({curr->right,{line+1,level+1}});
            }
        }
        
        for(auto p:nodes){
            vector<int> v;
            for(auto a:p.second){
                v.insert(v.end(),a.second.begin(),a.second.end());
            }
            ans.push_back(v);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        levelorder(root,ans);
        return ans;
    }
};