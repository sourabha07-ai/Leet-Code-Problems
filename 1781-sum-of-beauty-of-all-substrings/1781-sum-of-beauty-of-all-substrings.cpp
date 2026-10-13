
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int freq[26] = {};
            int countFreq[501] = {};
            int maxFreq = 0;
            int minFreq = 0;

            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                int oldFreq = freq[idx];

                // Remove character from its old frequency bucket
                if (oldFreq > 0) {
                    countFreq[oldFreq]--;
                }

                // Increase its frequency
                freq[idx]++;
                int newFreq = freq[idx];
                countFreq[newFreq]++;

                // Update minimum frequency
                if (oldFreq == 0) {
                    minFreq = 1;
                } else if (oldFreq == minFreq &&
                           countFreq[oldFreq] == 0) {
                    minFreq++;
                }

                // Update maximum frequency
                maxFreq = max(maxFreq, newFreq);

                // Add beauty
                ans += maxFreq - minFreq;
            }
        }

        return ans;
    }
};
