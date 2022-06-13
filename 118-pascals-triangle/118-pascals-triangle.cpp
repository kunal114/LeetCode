class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        if(numRows==0){
            return ans;
        }
        for(int i=0;i<numRows;i++){
            vector<int> v(i+1);
            v[0] = 1;
            v[i] = 1;
            int k =1;
            while(k<i){
                v[k] = ans[i-1][k-1] + ans[i-1][k];
                k++;
            }
            ans[i]=v;
        }
        return ans;
    }
};