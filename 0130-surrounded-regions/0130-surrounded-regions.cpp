const static auto initialize = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    bool check(int x,int y,int n,int m){
        return x>=0&&x<n&&y>=0&&y<m;
    }
    void solve(vector<vector<char>>& mat) {
        int n=mat.size(),m=mat[0].size();

        vector<vector<int>> vis(n,vector<int>(m));

        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O'){
                q.push({i,0});
                vis[i][0]=1;
            }
            if(mat[i][m-1]=='O'){
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
        }

        for(int j=0;j<m;j++){
            if(mat[0][j]=='O'){
                q.push({0,j});
                vis[0][j]=1;
            }
            if(mat[n-1][j]=='O'){
                q.push({n-1,j});
                vis[n-1][j]=1;
            }
        }

        vector<int> x={1,-1,0,0};
        vector<int> y={0,0,-1,1};

        while(!q.empty()){
            int a=q.front().first;
            int b=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int X=a+x[i],Y=b+y[i];
                if(check(X,Y,n,m)&&!vis[X][Y]&&mat[X][Y]=='O'){
                    q.push({X,Y});
                    vis[X][Y]=1;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O'&&!vis[i][j]) mat[i][j]='X';
            }
        }
    }
};