class Solution {
public:
    void rec(vector<int> nums,int i,vector<int> v,vector<vector<int>> &ans){
        ans.push_back(v);
        
        for(int ind=i;ind<nums.size();++ind){
            if(ind>i and nums[ind]==nums[ind-1]) continue;
            v.push_back(nums[ind]);
            rec(nums,ind+1,v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(),nums.end());
        rec(nums,0,v,ans);
        return ans;
    }
};