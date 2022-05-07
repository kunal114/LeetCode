class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        int minarray[n];
        stack<int> st;
        if(n>0)
        minarray[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            minarray[i]=min(minarray[i-1],nums[i]);
        }
       
        for(int j=n-1;j>=0;j--)
        {
            if(nums[j]>minarray[j])
            {
                while(st.size()>0 && st.top()<=minarray[j])
                    st.pop();
                if(st.size()>0 && st.top()<nums[j])
                    return true;
                st.push(nums[j]);
            }
            
        }
        return false;
    }
};