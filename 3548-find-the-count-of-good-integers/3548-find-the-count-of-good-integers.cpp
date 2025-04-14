#define ll long long
class Solution {
public:
    vector<vector<int>> pal;
    
    void generatePalindromes(int n, vector<int>& tmp) {
        if (tmp.size() == (n + 1) / 2) {
            pal.push_back(tmp);
            return;
        }
        for (int i = 0; i <= 9; i++) {
            if (tmp.empty() && i == 0) continue;
            tmp.push_back(i);
            generatePalindromes(n, tmp);
            tmp.pop_back();
        }
    }
    
    ll countPermutations(vector<int>& digits) {
        vector<int> count(10, 0);
        for (int d : digits) count[d]++;
        
        ll total = 1;
        int sum = accumulate(count.begin(), count.end(), 0);
        
        vector<ll> fact(sum + 1, 1);
        for (int i = 2; i <= sum; i++) fact[i] = fact[i-1] * i;
        
        total = fact[sum];
        for (int c : count) {
            if (c > 1) total /= fact[c];
        }
        
        if (count[0] > 0) {
            ll invalid = fact[sum-1];
            count[0]--;
            for (int c : count) {
                if (c > 1) invalid /= fact[c];
            }
            total -= invalid;
        }
        
        return total;
    }
    
    long long countGoodIntegers(int n, int k) {
        vector<int> tmp;
        generatePalindromes(n, tmp);
        
        ll res = 0;
        unordered_set<string> seen;
        
        for (auto& half : pal) {
            vector<int> digits = half;
            if (n % 2 == 1) {
                for (int i = half.size() - 2; i >= 0; i--) {
                    digits.push_back(half[i]);
                }
            } else {
                for (int i = half.size() - 1; i >= 0; i--) {
                    digits.push_back(half[i]);
                }
            }
            
            ll num = 0;
            for (int d : digits) {
                num = (num * 10 + d) % k;
            }
            if (num != 0) continue;
            
            // Create unique key for digit counts
            vector<int> count(10, 0);
            for (int d : digits) count[d]++;
            string key;
            for (int c : count) key += to_string(c) + ",";
            
            if (seen.find(key) == seen.end()) {
                seen.insert(key);
                res += countPermutations(digits);
            }
        }
        
        return res;
    }
};