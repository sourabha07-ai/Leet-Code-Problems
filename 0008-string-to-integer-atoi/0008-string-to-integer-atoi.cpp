
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        long long num = 0;

        // Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Handle sign
        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        // Convert digits
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');

            // Handle overflow
            if (sign == 1 && num > INT_MAX) {
                return INT_MAX;
            }

            if (sign == -1 && -num < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return (int)(num * sign);
    }
};
