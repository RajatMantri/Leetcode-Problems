class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long z1=0,s1=0,z2=0,s2=0;
        for(auto&i:nums1){
            z1+=i==0;
            s1+=i;
        }
        for(auto&i:nums2){
            z2+=i==0;
            s2+=i;
        }

        if(z2==0&&s1+z1>s2) return -1;
        if(z1==0&&s2+z2>s1) return -1;

        return max(s1+z1,s2+z2);
    }
};