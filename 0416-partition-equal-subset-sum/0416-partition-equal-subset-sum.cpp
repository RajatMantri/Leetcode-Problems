class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        
        for(int i=0;i<n;i++) sum+=nums[i];
        if(sum&1) return false;
        
        vector<bool> prev(sum/2+1);
        if(nums[0]<=sum/2) prev[nums[0]]=1;
        prev[0]=1;
        
        for(int i=1;i<n;i++){
            for(int f=sum/2;f>=nums[i];f--){
                prev[f]=prev[f-nums[i]]|prev[f];
            }
        }

        if(prev[sum/2]==1) return true;
        else return false;
    }
};