class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,res=0,count=0;
        long long n=s.length();
        vector<int> freq(3);
        for(int j=0;j<n;j++){
            if(freq[s[j]-'a']==0) count++;
            freq[s[j]-'a']++;

            while(count>2){
                freq[s[i]-'a']--;
                if(freq[s[i++]-'a']==0) count--;
            }

            res+=j-i+1;
        }
        return n*(n+1)/2-res;
    }
};