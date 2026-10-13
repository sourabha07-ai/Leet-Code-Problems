 
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int freq[26] = {};
            int maxFreq = 0;

            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                freq[idx]++;

                if (freq[idx] > maxFreq)
                    maxFreq = freq[idx];

                int minFreq = n;

                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0 && freq[k] < minFreq)
                        minFreq = freq[k];
                }

                ans += maxFreq - minFreq;
            }
        }

        return ans;
    }
};
