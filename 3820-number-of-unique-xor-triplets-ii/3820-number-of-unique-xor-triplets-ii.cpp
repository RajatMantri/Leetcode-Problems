class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) mp.insert(nums[i]^nums[j]);
        }
        
        unordered_set<int> ans;
        
        for(int i=0;i<n;i++){
            for(auto j:mp){
                ans.insert(j^nums[i]);
            }
        }
        
        return ans.size();
    }
};