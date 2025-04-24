class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_map<int,int> mp;
        long long i=0,count=0;
        long long sub=0;
        for(int j=0;j<n;j++){
            count+=mp[nums[j]];
            mp[nums[j]]++;

            while(count>=k){
                mp[nums[i]]--;
                count-=mp[nums[i]];
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }

            sub+=j-i+1;
        }

        return n*1LL*(n+1)/2-sub;
    }
};