class Solution {
public:
    int dp[105][105];
    int f(int i,int j,vector<int>& cuts){
        if(i==j-1) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int ans=cuts[j]-cuts[i];
        int steps=1e9;
        for(int k=i+1;k<j;k++){
            steps=min(steps,f(i,k,cuts)+f(k,j,cuts));
        }
        return dp[i][j]=steps+ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());

        memset(dp,-1,sizeof(dp));
        return f(0,cuts.size()-1,cuts);
    }
};