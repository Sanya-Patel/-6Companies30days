class Solution {
private:
    unordered_map<string, int> um;  // Dictionary words

    int solve(string& s, int ind) {
        // base condition, where recursion gets over
        if (ind >= s.size()) {
            return 0;
        }

        int extra = INT_MAX;
        string tmp = "";       

        // Try all substrings starting from the current index
        for (int i = ind; i < s.size(); i++) {
            tmp += s[i]; // string concatenation // intuit -> intuita -> intuitandcode

            if (um.find(tmp) != um.end()) {
                // If the substring is in the dictionary, solve for the remaining part
                extra = min(extra, solve(s, i + 1)); // andcode // code // 3 // 2
            }
        }

        // Consider the case where the current character is counted as extra
        // basically skipping the current ind = 0
        extra = min(extra, 1 + solve(s, ind + 1)); // 1,ndcode // 2, dcode // 3, code

        return extra;
    }

public:
    int minExtraChar(string s, vector<string>& dict) {
        // words = 1;
        for (auto& val : dict) {
            um[val]++;
        }

        return solve(s, 0);  // Start the recursion from index 0
    }
};