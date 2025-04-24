class Solution {
public:
    int atmost(vector<int>& nums,int un){
        unordered_map<int,int> f;
        int n=nums.size();
        int i=0,ans=0;
        for(int j=0;j<n;j++){
            f[nums[j]]++;

            if(f.size()>un){
                while(f.size()>un){
                    f[nums[i]]--;
                    if(f[nums[i]]==0) f.erase(nums[i]);
                    i++;
                }
            }
            ans+=j-i+1;
        }

        return ans;
    }
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto&i:nums) mp[i]++;
        int un=mp.size();

        int ff=atmost(nums,un);
        int ss=atmost(nums,un-1);

        return ff-ss;
    }
};