class Solution {
public:
    int countGoodNumbers(long long n) {
        int mod=(int)(1e9+7);
        long long pow4=n/2;
        long long pow5=(n&1)?n/2+1:n/2;
        long long num=4,ans=1;

        while(pow4!=0){
            if(pow4&1) ans=(ans*num)%mod;
            num=(num*num)%mod;
            pow4=pow4>>1;
        }
        
        num=5;
        while(pow5!=0){
            if(pow5&1) ans=(ans*num)%mod;
            num=(num*num)%mod;
            pow5=pow5>>1;
        }

        return ans;
    }
};