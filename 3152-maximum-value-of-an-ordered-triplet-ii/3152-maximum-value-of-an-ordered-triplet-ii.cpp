#define ll long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll ans=0;
        int n=nums.size();

        vector<int> mx(n);
        mx[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) mx[i]=max(mx[i+1],nums[i]);

        int mxi=nums[0];

        for(int i=1;i<n-1;i++){
            ans=max(ans,(mxi-nums[i])*1LL*mx[i+1]);
            mxi=max(mxi,nums[i]);
        }

        return ans;
    }
};