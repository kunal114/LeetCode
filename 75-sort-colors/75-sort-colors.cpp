class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0,j = n-1, mid = 0;
        while(mid<=j){
            if(nums[mid]==0){
                int temp = nums[i];
                nums[i] = nums[mid];
                nums[mid] = temp;
                i++;
                mid++;
            }
            else if(nums[mid]==2){
                int temp = nums[mid];
                nums[mid]=nums[j];
                nums[j]=temp;
                j--;
            }
            else{
                mid++;
            }
        }
    }
};