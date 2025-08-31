static auto speedup = []()  {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    return NULL;
}();
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi=0,n=nums.size();
        for(int i=0;i<n-1;i++){
            maxi=max(maxi-1,nums[i]);
            if(maxi<1){
                return false;
            }
        }
        return true;
    }
};