class Solution {
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {        
        vector<int> adj[n];
        
        for(auto&i:edges){
            adj[i[0]].push_back(i[1]);
        }
        
        vector<int> pre(n);
        
        for(int i=0;i<n;i++){
            for(auto&j:adj[i]){
                pre[j]|=(1<<i);
            }
        }
        
        vector<int> dp((1<<n),-1);
        int t=(1<<n);
        dp[0]=0;
        
        for (int i=0;i<t;i++) {
            int c=__builtin_popcount(i);
            if(dp[i]==-1) continue;
            for (int j=0;j<n;j++) {
                if (!(i&(1<<j))){
                    if ((pre[j]&i)==pre[j]){
                        int mask=i|(1<<j);
                        dp[mask]=max(dp[mask],dp[i]+score[j]*(c+1));
                    }
                }
            }
        }
        
        return dp[t-1];
    }
};