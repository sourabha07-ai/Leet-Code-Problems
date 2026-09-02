class Solution {
public:

    bool notValid(char ch) {
        if(ch >= 65 && ch <= 90) {
            return false;
        }
        else if(ch >= 97 && ch <= 122) {
            return false;
        }
        else if(ch >= 48 && ch <= 57) {
            return false;
        }
        else {
            return true;
        }
    }

    bool isPalindrome(string s) {
        int n = s.length();

        int i = 0;
        int j = n - 1;

        while(i < j) {

            char x = s[i];
            char y = s[j];

            // Convert uppercase to lowercase
            if(x >= 65 && x <= 90)
                x += 32;

            if(y >= 65 && y <= 90)
                y += 32;

            // Skip invalid characters
            if(notValid(x))
                i++;

            else if(notValid(y))
                j--;

            // Compare valid characters
            else {
                if(x != y)
                    return false;

                i++;
                j--;
            }
        }

        return true;
    }
};