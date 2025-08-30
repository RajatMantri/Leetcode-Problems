class Solution {
public:
    bool check(vector<vector<char>>& board,int x,int y,int num){
        for(int i=0;i<9;i++) if(board[i][y]==num+'0') return false;
        for(int j=0;j<9;j++) if(board[x][j]==num+'0') return false;
        for(int i=x/3*3;i<x/3*3+3;i++){
            for(int j=y/3*3;j<y/3*3+3;j++){
                if(board[i][j]-'0'==num) return false;
            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    char c=board[i][j];
                    board[i][j]='.';
                    if(!check(board,i,j,c-'0')) return false;
                    board[i][j]=c;
                }
            }
        }

        return true;
    }
};