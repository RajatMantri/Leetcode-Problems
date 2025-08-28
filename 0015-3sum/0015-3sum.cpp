class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        int n=nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            int l=i+1,r=n-1;

            while(l<r){
                int val=nums[l]+nums[r]+nums[i];
                if(val<0) l++;
                else if(val>0) r--;
                else{
                    int left=nums[l];
                    int right=nums[r];

                    while(l<r&&nums[l]==left) l++;
                    while(l<r&&nums[r]==right) r--;

                    ans.push_back({nums[i],left,right});
                }
            }
        }

        return ans;
    }
};