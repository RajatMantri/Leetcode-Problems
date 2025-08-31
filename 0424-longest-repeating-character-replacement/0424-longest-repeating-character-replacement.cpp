class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,ans=0;
        vector<int> freq(26);
        int maxi=0;//Freq of most occuring character till now
        for(int j=0;j<s.length();j++){
            freq[s[j]-'A']++;
            maxi=max(maxi,freq[s[j]-'A']);
            int len=j-i+1;

            while(len-maxi>k){
                freq[s[i++]-'A']--;
                for(int i=0;i<26;i++){
                    maxi=max(maxi,freq[i]);
                }
                len--;
            }

            ans=max(ans,len);
        }
        return ans;
    }
};