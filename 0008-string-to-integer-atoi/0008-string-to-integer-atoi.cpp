class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.length();
        int sign = 1;

        
        while (i < n && s[i] == ' ') {
            i++;
        }

       
        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        
        long long digit = 0;

        while (i < n && isdigit(s[i])) {

            int current = s[i] - '0';

    
            if (digit > (INT_MAX - current) / 10) {
                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }

            digit = digit * 10 + current;

            i++;
        }

        
        return digit * sign;
    }
};