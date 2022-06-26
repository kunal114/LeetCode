class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> v;
        int n=nums.size();
      unordered_map<int,int> mp;
	  for(int i=0;i<n;i++) mp[nums[i]]++;
	  priority_queue<pair<int,int>> pq;
	  for(auto it: mp)
	     pq.push({it.second, -1*it.first});
	     
	   
	 while(pq.size()>0) 
	 {
	     int val=-1*pq.top().second;
	     int freq=pq.top().first;
	     while(freq--)
	     {
	         v.push_back(val);
	     }
	     pq.pop();
	 }
        reverse(v.begin(),v.end());
        return v;
    }
    
};