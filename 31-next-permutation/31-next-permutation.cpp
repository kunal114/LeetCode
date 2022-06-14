class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind1, ind2;
        int n = nums.size();
        for(int i = n-2; i >=0 ;i--){
            if(nums[i+1]>nums[i]){
                ind1 = i;
                break;
            }
        }
        if(ind1<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(int i = n-1; i > ind1 ;i--){
                if(nums[i]>nums[ind1]){
                    ind2 = i;
                    break;
                }
            }
            int temp = nums[ind1];
            nums[ind1] = nums[ind2];
            nums[ind2] = temp;
            reverse(nums.begin()+ind1+1,nums.end());
        }
        
        cout<<ind1<<" "<<ind2;
    }
};