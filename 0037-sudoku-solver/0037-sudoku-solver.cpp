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
    bool f(vector<vector<char>>& board,int x,int y){
        if(x==9) return true;
 
        if(board[x][y]!='.') return f(board,x+(y+1)/9,(y+1)%9);

        for(int num=1;num<=9;num++){
            if(check(board,x,y,num)){
                board[x][y]=num+'0';
                if(f(board,x+(y+1)/9,(y+1)%9)) return true;
                board[x][y]='.';
            }
        }

        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        f(board,0,0);
    }
};