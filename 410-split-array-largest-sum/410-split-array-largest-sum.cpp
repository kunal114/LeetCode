class Solution {
public:
bool isPossible(vector<int> array, int n, int K, int mid)
{
    int count = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] > mid)
            return false;
        sum += array[i];
        if (sum > mid) {
            count++;
            sum = array[i];
        }
    }
    count++;
    if (count <= K)
        return true;
    return false;
}
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int low = 0;
        int high= 0;
        for(int i=0;i<n;i++){
            high+=nums[i];
            low=max(low,nums[i]);
        }
        
        int ans=0;
        while(low<=high){
            int mid = (low+high)/2;
            if(isPossible(nums,n,m,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};