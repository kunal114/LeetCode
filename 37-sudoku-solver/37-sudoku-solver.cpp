char v[11] = {'0','1','2','3','4','5','6','7','8','9'};
class Solution {
public:
    bool possible(vector<vector<char>> board,int x,int y,int no,int n,char v[]){
        //row and col check
        for(int k=0;k<n;k++){
            if(board[x][k]==v[no]||board[k][y]==v[no]){
                return false;
            }
        }
        //subgrid check
        int Sx=(x/3)*3,Sy=(y/3)*3;
        for(int i=Sx;i<Sx+3;i++){
            for(int j=Sy;j<Sy+3;j++){
                if(board[i][j]==v[no]){
                    return false;
                }
            }
        }
        return true;
    }
    bool sudoku(vector<vector<char>> &board, int n ,int row, int col, char v[]){
        if(row==n){
            return true;
        }
        
        //last column, shift to next row
        if(col==n){ return sudoku(board,n,row+1,0,v);}
        
        //ignore prefilled cell as we dont have to alter that cell, so move to next cell
        if(board[row][col]!='.'){return sudoku(board,n,row,col+1,v);}
        
        //now try filling the cell with all possibilities(1-9)
        for(int no=1;no<=n;no++){
            if(possible(board,row,col,no,n,v)){
                board[row][col] = v[no];
                if(sudoku(board,n,row,col+1,v)){return true;}
            }
        }
        board[row][col] = '.';
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        bool ans = sudoku(board,9,0,0,v);
    }
};