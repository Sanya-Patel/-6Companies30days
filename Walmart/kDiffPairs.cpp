class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 1;
        int diff = 0; // nums[j]-nums[i]==k
        int cnt = 0;
        while (i < n and j < n) {
            diff = nums[j] - nums[i];
            if (diff == k) {
                cnt += 1;
                i += 1;
                j += 1;
                while(nums[j]==nums[j-1])
                {
                    j++;
                }
            } else if (diff < k) {
                j += 1;
            } else if (diff > k) { // Diff>k
                i += 1;
                if (i == j) {
                    j += 1;
                }
            }
        }
        return cnt;
    }
};