#define ll long long
class Solution {
public:
    ll solve(vector<int>&nums,int k){
        int n=nums.size();
        ll ans=0;
        for(int i=0;i<n;i++){
            int c=upper_bound(nums.begin(),nums.end(),k-nums[i])-nums.begin();
            ans+=min(c,i);
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        return (solve(nums,upper)-solve(nums,lower-1));
    }
};