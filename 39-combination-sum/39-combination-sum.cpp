class Solution {
public:
    void recursion(vector<int> candidates,int n,int sum,int i,int curr,vector<int> comb,vector<vector<int>> &ans){
        if(i==n){
            if(curr==0){
                ans.push_back(comb);
                return;
            }
            return;
        }
        if(candidates[i]<=curr){
            comb.push_back(candidates[i]);
            recursion(candidates,n,sum,i,curr-candidates[i],comb,ans);
            comb.pop_back();
        }
        
        recursion(candidates,n,sum,i+1,curr,comb,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        int curr=target,i=0;
        recursion(candidates,candidates.size(),target,i,curr,comb,ans);
        return ans;
    }
};