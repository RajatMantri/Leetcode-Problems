class Solution {
public:
    void solve(string digits,int index,string output,vector<string> &ans, map<char,string> mapp){
        if(digits.length()==index){
            ans.push_back(output);
            return;
        }
        char num=digits[index];
        string element=mapp[num];
        for(auto &k:element){
            output.push_back(k);
            solve(digits,index+1,output,ans,mapp);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        map<char,string> mapp;
mapp['2']="abc";mapp['3']="def";mapp['4']="ghi";mapp['5']="jkl";mapp['6']="mno";mapp['7']="pqrs";mapp['8']="tuv";mapp['9']="wxyz";
        vector<string> ans;
        if(digits=="") return ans;
        string output="";
        solve(digits,0,output,ans,mapp);
        return ans;
    }
};