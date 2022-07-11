class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mn = nums[0];
        int mx = nums[0];
        int res = nums[0];
        
        for(int i=1;i<nums.size();i++){
            int curr = nums[i];
            if(curr==0){
                mn = 1;
                mx = 1;
            }
            int temp1=curr*mx;
            int temp2=curr*mn;
            
            mx = max(temp1,temp2);
            mx = max(mx,curr);
            mn = min(temp1,temp2);
            mn = min(mn,curr);
            
            res = max(res,mx);
        }
        
        return res;
    }
};