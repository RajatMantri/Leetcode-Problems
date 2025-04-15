#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long ans=0;
        int n=nums1.size();

        ordered_set a,b;
        vector<int> pos(n);
        for(int i=0;i<n;i++){
            pos[nums1[i]]=i;
        }

        for(auto&i:nums2){
            b.insert(-pos[i]);
        }

        a.insert(pos[nums2[0]]);
        b.erase(-pos[nums2[0]]);

        for(int i=1;i<n-1;i++){
            b.erase(-pos[nums2[i]]);
            ans+=(a.order_of_key(pos[nums2[i]]))*(b.order_of_key(-pos[nums2[i]]));
            a.insert(pos[nums2[i]]);
        }

        return ans;
    }
};