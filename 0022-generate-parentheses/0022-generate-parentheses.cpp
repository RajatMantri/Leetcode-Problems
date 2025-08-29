class Solution {
public:
    vector<string> ans;
    void f(int open,int close,int n,string&temp){
        if(open==n&&close==n){
            ans.push_back(temp);
            return;
        }
        int curr=open-close;
        if(curr==0){
            temp.push_back('(');
            if(open<n) f(open+1,close,n,temp);
            temp.pop_back();
        }
        else{
            temp.push_back('(');
            if(open<n) f(open+1,close,n,temp);
            temp.pop_back();

            temp.push_back(')');
            if(close<n) f(open,close+1,n,temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp;
        f(0,0,n,temp);
        return ans;
    }
};