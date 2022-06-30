bool compare(string x,string y){
    string xy = x.append(y);
    string yx = y.append(x);
    return xy.compare(yx)>0?true:false;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        string ans;
        
        for(int i=0;i<nums.size();i++){
            v.push_back(to_string(nums[i]));
        }
        sort(v.begin(),v.end(),compare);
        
        for(int i=0;i<v.size();i++){
            ans+=v[i];
        }
        if(ans[0] == '0')
            return "0";
        return ans;
    }
};