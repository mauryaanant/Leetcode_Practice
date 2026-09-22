class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int > counts;
        for(char c:s){
            counts[c]++;
        }

        int length =0;
        bool hasOdd = false;

        for (auto const&[ch, count] : counts){
            if (count %2 ==0){
                length += count; 
            } else {
                length += count-1;
                hasOdd = true;
            }
        }
        
        if (hasOdd){
            length +=1;
        }

        return length;
    }
};

