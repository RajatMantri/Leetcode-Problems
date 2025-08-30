class Solution {
public:
    void f(int row,int n,vector<vector<string>> &ans,vector<string> &temp,vector<bool> &diagonalL,vector<bool> &diagonalR,vector<bool> &column){
        if(row==n){
            ans.push_back(temp);
            return;
        }

        for(int col=0;col<n;col++){
            string poss(n,'.');
            if(diagonalL[col+row]==0&&diagonalR[col-row+n-1]==0&&column[col]==0){
                poss[col]='Q';
                diagonalL[col+row]=1;
                diagonalR[col-row+n-1]=1;
                column[col]=1;
                temp.push_back(poss);

                f(row+1,n,ans,temp,diagonalL,diagonalR,column);

                temp.pop_back();
                poss[col]='.';
                diagonalL[col+row]=0;
                diagonalR[col-row+n-1]=0;
                column[col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp;
        
        vector<bool> diagonalL(n*2);
        vector<bool> diagonalR(n*2);
        vector<bool> col(n); 
        
        f(0,n,ans,temp,diagonalL,diagonalR,col);

        return ans;
    }
};