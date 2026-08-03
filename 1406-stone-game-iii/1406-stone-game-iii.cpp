#include <vector>
#include <string>
#include <algorithm>
#include <climits>

class Solution {
public:
    std::string stoneGameIII(std::vector<int>& stoneValue) {
        int n = stoneValue.size();
        // dp[i] represents the maximum relative score (current player's score - opponent's score) 
        // starting from stone i.
        std::vector<int> dp(3, 0); 
        
        for (int i = n - 1; i >= 0; --i) {
            int current_sum = 0;
            int max_diff = INT_MIN;
            
            // The current player can take 1, 2, or 3 stones
            for (int k = 1; k <= 3 && i + k - 1 < n; ++k) {
                current_sum += stoneValue[i + k - 1];
                int remaining_diff = dp[(i + k) % 3];
                int diff = current_sum - remaining_diff;
                max_diff = std::max(max_diff, diff);
            }
            
            // Store the result for the current starting index
            dp[i % 3] = max_diff;
        }
        
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};