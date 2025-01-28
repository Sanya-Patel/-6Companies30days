class Solution {
public:
    void backtrack(int k, int n, int start, vector<int>& combination,
                   vector<vector<int>>& result) {
        if (combination.size() == k) {
            if (n == 0) {
                result.push_back(combination);
            }
            return;
        }

        for (int i = start; i <= 9; ++i) {
            if (i > n)
                break;
            combination.push_back(i);
            backtrack(k, n - i, i + 1, combination, result);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(k, n, 1, combination, result);
        return result;
    }
};