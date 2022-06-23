class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0;
        int high=nums.size()-2;
        
        while(low<=high){
            int mid = (low+high)/2;
            
            //check if mid lies in left half(Fix this condition) or not(in the left half fi=even and se=odd)
            if(mid%2==0){
                //if lies then
                if(nums[mid]==nums[mid+1]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }//now if we are on an odd index the previous element should match(Acc to left window)
            else{
                if(nums[mid]==nums[mid-1]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return nums[low];
    }
};