class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        for(int i=1;i<n;i++){
            string temp;
            int j=0;
            while(j<ans.length()){
                int k=j;
                while(j<ans.length()&&ans[k]==ans[j]) j++;
                int no=j-k;
                temp=temp+to_string(no);
                temp.push_back(ans[k]);
            }
            ans=temp;
        }
        return ans;
    }
};