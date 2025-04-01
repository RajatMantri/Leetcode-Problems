#define ll long long
class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n=q.size();

        ll dp[n+1];
        dp[n]=0;

        for(int i=n-1;i>=0;i--){
            dp[i]=dp[min(n,i+q[i][1]+1)]+q[i][0];
            dp[i]=max(dp[i+1],dp[i]);
        }

        return dp[0];
    }
};