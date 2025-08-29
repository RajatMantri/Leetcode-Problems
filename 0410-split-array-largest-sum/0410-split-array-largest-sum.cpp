static auto speedup = []()  {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    return NULL;
}();
#define ll long long 
class Solution {
public:
    int count(vector<int>& nums,ll mid){
        ll n=1,sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mid) sum+=nums[i];
            else{
                n++;
                if(nums[i]<=mid) sum=nums[i];
                else return INT_MAX;
            }
        }
        return n;
    }
    int splitArray(vector<int>& nums, int k) {
        ll s=0,e=accumulate(nums.begin(),nums.end(),0),ans=-1;
        while(s<=e){
            ll mid=(s+e)/2;
            int n=count(nums,mid);//Number of subarrays
            if(k>=n){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};