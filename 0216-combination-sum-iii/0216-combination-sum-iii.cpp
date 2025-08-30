class Solution {
public:
    void f(int rem,int target,vector<vector<int>> &ans,vector<int> &temp,int num){
        if(rem==0&&target==0){
            ans.push_back(temp);
            return;
        }
        if(num>=10){
            //if(rem==0&&target==0) ans.push_back(temp);
            return;
        }

        f(rem,target,ans,temp,num+1);

        temp.push_back(num);
        f(rem-1,target-num,ans,temp,num+1);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(k,n,ans,temp,1);
        return ans;
    }
};