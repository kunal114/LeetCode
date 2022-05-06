class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        
        int j = 0;
        int count = 0;
        if(n==0){
            return 0;
        }
        if(n==1 and nums[0]==val){
            return 0;
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=val){
                nums[j]= nums[i];
                j++;
            }
        }
        return j;
    }
};