const static auto initialize = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0,n=nums.size();
        int i=0,maxi=*max_element(nums.begin(),nums.end());
        int count=0;
        for(int j=0;j<n;j++){
            if(nums[j]==maxi) count++;

            while(count>=k){
                if(nums[i]==maxi) count--;
                i++;
            }

            ans+=j-i+1;
        }

        n=n*(n+1)/2;
        return n-ans;
    }
};