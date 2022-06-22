class Solution {
public:
    bool isSafe(vector<string> board,int x,int y,int n){
        //col check(fix column)
        for(int k=0;k<x;k++){
            if(board[k][y]=='Q'){
                return false;
            }
        }
        
        //row check(fix row)
        for(int k=0;k<x;k++){
            if(board[x][k]=='Q'){
                return false;
            }
        }
        
        //left diagnol
        int i=x;
        int j=y;
        while(i>=0 and j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        
        //right diagnol
        i=x;
        j=y;
        while(i>=0 and j<n){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j++;
        }
        
        return true;
    }
    void nQueen(vector<string> board,int n,int row,vector<vector<string>> &ans){
        if(row==n){
            ans.push_back(board);
            return;
        }
        
        for(int col=0;col<n;col++){
            if(isSafe(board,row,col,n)){
                board[row][col] = 'Q';
                nQueen(board,n,row+1,ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; //contains more than one board
        vector<string> board(n);//1 board with n rows
        string s(n,'.');//each row for a board
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        int row=0;
        nQueen(board,n,row,ans);
        return ans;
    }
};