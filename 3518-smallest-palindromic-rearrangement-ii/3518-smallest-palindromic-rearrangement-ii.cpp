class Solution {
public:
    string smallestPalindrome(string s, long long k) {
        int n = s.size();
        int half = n / 2;
        vector<long long> cnt(26, 0);
        for (int i = 0; i < half; i++) {
            cnt[s[i] - 'a']++;
        }

        const long long CAP = 2e18;

        auto countPerms = [&](vector<long long>& c, int total) -> long long {
            long long result = 1;
            int remaining = total;
            for (int ch = 0; ch < 26; ch++) {
                long long x = c[ch];
                remaining -= x;
            }
            return result;
        };

        auto permCountCapped = [&](vector<long long> c,
                                   int total) -> long long {
            long double logResult = lgamma(total + 1);
            for (int ch = 0; ch < 26; ch++) {
                if (c[ch] > 0)
                    logResult -= lgamma(c[ch] + 1);
            }
            if (logResult > 42)
                return CAP;
            long long result = (long long)round(expl(logResult));
            return result;
        };

        long long totalPerms = permCountCapped(cnt, half);
        if (k > totalPerms)
            return "";

        string result(half, ' ');
        int remaining = half;

        for (int pos = 0; pos < half; pos++) {
            for (int ch = 0; ch < 26; ch++) {
                if (cnt[ch] == 0)
                    continue;
                cnt[ch]--;
                long long cntPerms = permCountCapped(cnt, remaining - 1);
                if (k > cntPerms) {
                    k -= cntPerms;
                    cnt[ch]++;
                } else {
                    result[pos] = 'a' + ch;
                    remaining--;
                    break;
                }
            }
        }

        string ans = result;
        if (n % 2 == 1) {
            ans += s[half];
        }
        for (int i = half - 1; i >= 0; i--) {
            ans += result[i];
        }
        return ans;
    }
};