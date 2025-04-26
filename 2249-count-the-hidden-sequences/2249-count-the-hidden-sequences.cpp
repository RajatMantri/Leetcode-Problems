class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int mini=lower,maxi=upper;

        for(auto&i:differences){
            mini=max(lower,i+mini);
            maxi=min(upper,i+maxi);

            if(mini>maxi) return 0;
        }

        return maxi-mini+1;
    }
};