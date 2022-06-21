class Solution {
public:
    void recursion(vector<int> arr,int i,int curr,vector<int> comb,vector<vector<int>> &ans){
        if(i==arr.size()){
            if(curr==0){
                ans.push_back(comb);
                return;
            }
            return;
        }
        if(arr[i]<=curr){
            comb.push_back(arr[i]);
            recursion(arr,i,curr-arr[i],comb,ans);
            comb.pop_back();
        }
        
        recursion(arr,i+1,curr,comb,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        int curr=target,i=0;
        recursion(candidates,i,curr,comb,ans);
        return ans;
    }
};