class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        for(int i=0;i<n;i++){
            int temp = nums[i];
            if(s.find(temp-1)==s.end()){
                temp++;
                int cnt = 1;
                while(s.find(temp)!=s.end()){
                    cnt++;
                    temp++;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};