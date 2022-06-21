class Solution {
public:
    void rec(vector<int> arr,int i,int target,vector<int> v,vector<vector<int>> &ans){
        //Base case
        if(i==arr.size()){
            if(target==0){
                ans.push_back(v);
                return;
            }
            return;
        }
        
        //Rec case
        if(arr[i]<=target){
            v.push_back(arr[i]);
            rec(arr,i,target-arr[i],v,ans);
            v.pop_back();
        }
        rec(arr,i+1,target,v,ans);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        rec(candidates,0,target,v,ans);
        return ans;
    }
};