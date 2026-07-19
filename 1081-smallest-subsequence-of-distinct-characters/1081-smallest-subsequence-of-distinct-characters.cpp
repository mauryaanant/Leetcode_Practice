class Solution {
public:
    string smallestSubsequence(string s) {
        int lastIndex[26] = {};
        for (int i = 0; i < s.size(); i++)
            lastIndex[s[i] - 'a'] = i;

        bool inStack[26] = {};
        string stack = "";

        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';

            if (inStack[c]) continue;
            
            while (!stack.empty() && stack.back() > s[i] 
                   && lastIndex[stack.back() - 'a'] > i) {
                inStack[stack.back() - 'a'] = false;
                stack.pop_back();
            }

            stack.push_back(s[i]);
            inStack[c] = true;
        }

        return stack;
    }
};