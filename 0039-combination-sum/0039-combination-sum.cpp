const static auto initialize = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    void f(vector<int>& candidates,vector<vector<int>> &ans,vector<int> &temp,int target,int i){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i==candidates.size()){
            return;
        }

        f(candidates,ans,temp,target,i+1);

        if(target>=candidates[i]){
            temp.push_back(candidates[i]);
            f(candidates,ans,temp,target-candidates[i],i);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(candidates,ans,temp,target,0);
        return ans;
    }
};