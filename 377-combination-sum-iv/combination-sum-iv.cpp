class Solution {
public:
    unordered_map<int, int> memo;

    int combinationSum4(vector<int>& nums, int target) {
        if (target == 0) return 1;
        if (memo.count(target)) return memo[target];
        
        int ways = 0;
        for (int num : nums) {
            if (target >= num) {
                ways += combinationSum4(nums, target - num);
            }
        }
        
        memo[target] = ways;
        return ways;
    }
};