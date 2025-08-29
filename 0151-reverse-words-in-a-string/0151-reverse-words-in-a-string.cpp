class Solution {
public:
    string reverseWords(string s) {
        string ans="";

        int j=s.length()-1;

        while(j>=0){
            stack<char> tmp;
            while(j>=0&&s[j]!=' ') tmp.push(s[j--]);

            if(!tmp.empty()){
                while(!tmp.empty()) ans.push_back(tmp.top()),tmp.pop();
                ans.push_back(' ');
            }

            while(j>=0&&s[j]==' ') j--;
        }

        return ans.substr(0,ans.length()-1);
    }
};