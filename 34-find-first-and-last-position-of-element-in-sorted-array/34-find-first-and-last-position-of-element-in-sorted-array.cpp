class Solution {
public:
    int binary(vector<int> nums,int target,int low,int high,int move){
        if(high<low) return -1;
        int ans=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>target){
                high= mid-1;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else{
                ans = mid;
                if(move==-1){
                    high = mid+move;
                }
                else{
                    low = mid+move;
                }
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        int first = binary(nums,target,0,n-1,-1);
        int last = binary(nums,target,0,n-1,1);
        ans.push_back(first);
        ans.push_back(last);

        return ans;
    }
};