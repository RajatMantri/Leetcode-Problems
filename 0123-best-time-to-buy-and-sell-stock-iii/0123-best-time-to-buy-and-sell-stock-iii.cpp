class Solution {
public:
    int f(vector<int>& prices,int i,bool buy,int rem,vector<vector<vector<int>>> &dp){
        if(rem==0) return 0;
        if(i==prices.size()){
            if(!buy) return -1e9;
            else return 0;
        }

        if(dp[i][buy][rem]!=-1) return dp[i][buy][rem];

        int np=f(prices,i+1,buy,rem,dp);
        int p;
        if(buy) p=-prices[i]+f(prices,i+1,0,rem,dp);
        else p=prices[i]+f(prices,i+1,1,rem-1,dp);

        return dp[i][buy][rem]=max(p,np);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(prices,0,1,2,dp);
    }
};