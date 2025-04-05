class Solution {
public:
    int f(int n,int i,int xr,vector<int>&nums){
        if(i==n) return xr;

        int pick=f(n,i+1,xr^nums[i],nums);
        int notPick=f(n,i+1,xr,nums);

        return pick+notPick;
    }
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        return f(n,0,0,nums);
    }
};