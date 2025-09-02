class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> ways(n,1);
        int maxi=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]&&dp[i]<dp[j]+1){
                    ways[i]=ways[j];
                    dp[i]=dp[j]+1;
                } 
                else if(nums[j]<nums[i]&&dp[i]==dp[j]+1) ways[i]+=ways[j];
            }
            maxi=max(maxi,dp[i]);
        }

        int res=0;
        for(int i=0;i<n;i++){
            if(maxi==dp[i]) res+=ways[i];
        }

        return res;
    }
};