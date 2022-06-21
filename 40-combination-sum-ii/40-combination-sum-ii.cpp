class Solution {
public:
    void rec(vector<int> arr,int i,int target,vector<int> v,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(v);
            return;
        }
            
        for(int ind=i;ind<arr.size();++ind){
            if(ind>i and arr[ind-1]==arr[ind]) continue;
            if(arr[ind]>target) break;
            v.push_back(arr[ind]);
            rec(arr,ind+1,target-arr[ind],v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        rec(candidates,0,target,v,ans);
        return ans;
    }
};