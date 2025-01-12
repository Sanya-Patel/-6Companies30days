class Solution {
public:
    bool solve(int idx, string s, unordered_set<string>& setmp,
               vector<int>& Dp) {
        if (idx >= s.size()) {
            return true;
        }
        if (setmp.find(s.substr(idx, s.size() - idx)) != setmp.end()) {
            return true;
        }
        if (Dp[idx] != 0) {
            return Dp[idx];
        }
        for (int l = 1; l <= s.size() - idx; l++) {
            string st = s.substr(idx, l);
            if (setmp.find(st) != setmp.end()) {
                if (solve(idx + l, s, setmp, Dp)) {
                    return Dp[idx] = true;
                }
            }
        }
        // Dp[idx] = false;
        return Dp[idx];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> setmp(wordDict.begin(), wordDict.end());
        vector<int> Dp(s.size(), 0);
        return solve(0, s, setmp, Dp);
    }
};