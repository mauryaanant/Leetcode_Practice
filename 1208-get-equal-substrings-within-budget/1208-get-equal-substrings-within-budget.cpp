class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int start = 0;
        int end = 0;
        int ans = 0;
        int currentCost = 0;

        while (end < s.length()) {
            currentCost += std::abs(s[end] - t[end]);

            while (currentCost > maxCost) {
                currentCost -= std::abs(s[start] - t[start]);
                start++;
            }

            ans = std::max(ans, end - start + 1);
            end++;
        }

        return ans;
    }
};