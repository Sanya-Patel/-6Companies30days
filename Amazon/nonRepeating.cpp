class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        int ans = -1;
        int c = 0;
        
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (mp[s[i]] == 1) {
                c += 1;
                if (c == 1) {
                    return i;
                }
            }
        }
        
        return ans;
    }
};
