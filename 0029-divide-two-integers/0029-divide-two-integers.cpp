class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==-1&&dividend==INT_MIN) return INT_MAX;

        unsigned ans=0,n=abs((long)dividend);
        bool neg=0;
        if((dividend<0&&divisor>0)||(dividend>0&&divisor<0)) neg=1;
        divisor=abs((long)divisor);

        while(n>=divisor){
            unsigned mask=divisor,i=0;
            if(mask==n){
                ans+=1;break;
            }
            while(mask<n){
                i++;
                mask=mask<<1;
            }
            i--;
            mask=mask>>1;

            ans+=1<<i;
            n-=mask;
        }
        
        if(neg) ans=-ans;
        return ans;
    }
};