class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int,int> f;
        
        for(auto&i:nums){
            if(i<k) return -1;
            f[i]++;
        }

        if((*f.begin()).first!=k) return f.size();

        return f.size()-1;
    }
};