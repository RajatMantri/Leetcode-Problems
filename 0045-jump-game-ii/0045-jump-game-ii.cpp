static auto speedup = []()  {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    return NULL;
}();
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1e9);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]>=i-j) dp[i]=min(dp[i],dp[j]+1);
            }
        }
        return dp[n-1];
    }
};