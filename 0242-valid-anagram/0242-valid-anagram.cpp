class Solution {
public:
    bool isAnagram(string s1, string s2) {
     
     if (s1.length() != s2.length()) {
        cout << "Not Anagram";
        return false;
    }

    int freq[26] = {0};

    for (int i = 0; i < s1.length(); i++) {
        freq[s1[i] - 'a']++;
        freq[s2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            cout << "Not Anagram";
            return false;
        }
    }

    return true;

        // if(s.length() != t.length()) return false;
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // if(s==t) return true;
        // else return false;   
    }
};