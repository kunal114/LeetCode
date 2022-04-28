class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ans;
        int n=nums.size();
        unordered_map<int,int> s;
        
        for(int i=0;i<n;i++){
            int temp=target-nums[i];
            if(s.find(temp)!=s.end()){
                ans.push_back(s[temp]);
                ans.push_back(i);
                return ans;
            }
            
            s[nums[i]]=i;
        }
        return ans;
    }
};