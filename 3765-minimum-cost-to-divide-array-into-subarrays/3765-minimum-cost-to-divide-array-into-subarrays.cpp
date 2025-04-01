#define ll long long
class Solution {
public:
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        int n=nums.size();

        vector<ll> pp(n);
        pp[0]=nums[0];

        vector<ll> qq(n);
        qq[0]=cost[0];
        
        for(int i=1;i<n;i++) pp[i]=pp[i-1]+nums[i];
        for(int i=1;i<n;i++) qq[i]=qq[i-1]+cost[i];

        vector<ll> dp(n+1,1e15);
        dp[n]=0;

        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                ll val1=qq[n-1];
                ll val2=pp[j];
                if(i>0) val1-=qq[i-1],val2-=pp[i-1];
                dp[i]=min(dp[i],val1*(val2+k)+dp[j+1]);
            }
        }

        return dp[0];
    }
};