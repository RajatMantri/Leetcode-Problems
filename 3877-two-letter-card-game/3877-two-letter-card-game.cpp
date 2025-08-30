#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
    int getPairs(int total, int largestGroup) {
        if (total <= 1) return 0;
        return min(total / 2, total - largestGroup);
    }

public:
    int score(vector<string>& cards, char x) {
        map<char, int> leftGroup, rightGroup;
        int doubleX = 0;
        string target = {x, x};

        for (auto& c : cards) {
            if (c.find(x) == string::npos) continue;
            if (c == target) doubleX++;
            else if (c[0] == x) leftGroup[c[1]]++;
            else rightGroup[c[0]]++;
        }

        int leftTotal = 0, leftMax = 0;
        for (auto& p : leftGroup) {
            leftTotal += p.second;
            leftMax = max(leftMax, p.second);
        }

        int rightTotal = 0, rightMax = 0;
        for (auto& p : rightGroup) {
            rightTotal += p.second;
            rightMax = max(rightMax, p.second);
        }

        int best = 0;
        for (int i = 0; i <= doubleX; i++) {
            int total1 = leftTotal + i;
            int max1 = max(leftMax, i);
            int score1 = getPairs(total1, max1);

            int total2 = rightTotal + (doubleX - i);
            int max2 = max(rightMax, doubleX - i);
            int score2 = getPairs(total2, max2);

            best = max(best, score1 + score2);
        }
        return best;
    }
};