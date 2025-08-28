static auto speedup = []()  {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    return NULL;
}();
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0,n=nums.size(),r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target) return true;
            
            if(nums[l]==nums[mid]){
                while(l<=mid&&nums[l]==nums[mid]) l++;
                continue;
            }
            
            if(nums[r]==nums[mid]){
                while(r>=mid&&nums[r]==nums[mid]) r--;
                continue;
            }

            //Left half sorted
            if(nums[l]<=nums[mid]){
                if(nums[l]<=target&&target<nums[mid]){
                    r=mid-1;
                }
                else l=mid+1;
            }
            //Right half sorted
            else {
                if(nums[mid]<target&&target<=nums[r]){
                    l=mid+1;
                }
                else r=mid-1;
            }
        }
        return false;
    }
};