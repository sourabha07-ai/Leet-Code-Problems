class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for (char c : word)
            freq[c - 'a']++;

        sort(freq.begin(), freq.end());

        int cnt = 0;
        int ans = 0;

        for (int i = 25; i >= 0; i--) {
            if (freq[i] > 0)
                cnt++;

            if (cnt <= 8)
                ans += freq[i];
            else if (cnt <= 16)
                ans += freq[i] * 2;
            else if (cnt <= 24)
                ans += freq[i] * 3;
            else
                ans += freq[i] * 4;
        }

        return ans;
    }
};