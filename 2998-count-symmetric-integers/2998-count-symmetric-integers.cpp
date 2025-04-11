class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);

            int n=s.length();
            if(n&1) continue;

            int sum=0;

            for(int i=0;i<n/2;i++){
                sum+=s[i]-s[n-1-i];
            }

            if(!sum) count++;
        }
        return count;
    }
};