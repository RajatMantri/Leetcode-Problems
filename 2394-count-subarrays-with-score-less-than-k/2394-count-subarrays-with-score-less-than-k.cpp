#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int i=0,n=nums.size();
        ll ans=0;

        ll sum=0;

        for(int j=0;j<n;j++){
            sum+=nums[j];

            while(sum*(j-i+1)>=k){
                sum-=nums[i++];
            }

            ans+=j-i+1;
        }

        return ans;
    }
};