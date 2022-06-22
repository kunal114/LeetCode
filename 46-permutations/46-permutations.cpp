class Solution {
public:
    void perm(vector<int> &nums,int i,vector<vector<int>> &ans){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int j=i;j<nums.size();j++){
            swap(nums[j],nums[i]);
            perm(nums,i+1,ans);
            swap(nums[j],nums[i]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        perm(nums,0,ans);
        return ans;
    }
};