const static auto initialize = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    bool check(int x,int y,int n,int m){
        return x>=0&&x<n&&y>=0&&y<m;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();

        vector<vector<int>> vis(n,vector<int>(m));
        vector<vector<int>> dist(n,vector<int>(m));

        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }

        int level=0;

        vector<int> x={1,-1,0,0};
        vector<int> y={0,0,-1,1};

        while(!q.empty()){
            int size=q.size();
            while(size--){
                int a=q.front().first,b=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int X=x[i]+a,Y=y[i]+b;
                    if(check(X,Y,n,m)&&vis[X][Y]==0){
                        vis[X][Y]=1;
                        dist[X][Y]=level+1;
                        q.push({X,Y});
                    }
                }
            }
            level++;
        }

        return dist;
    }
};