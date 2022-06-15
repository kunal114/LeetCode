class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ind = 0;
        for(int i=0;i<m;i++){
            if(matrix[i][0] <= target and matrix[i][n-1] >= target){
                break;
            }
            else{
                ind++;
            }
        }
        if(ind>=m){
            return false;
        }else{
            for(int i=0;i<n;i++){
                if(matrix[ind][i] == target){
                    return true;
                }
            }
        }
        return false;
    }
};