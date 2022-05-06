class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        int count = 0;
        if(n==1){
            return 1;
        }
        if(n==0){
            return 0;
        }
        int j=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1]){
                nums[j] = nums[i];
                j++;
                count++;
            }
        }
        nums[j++] = nums[n-1];

        count++;
        cout<<count;
        return count;
        
    }
};