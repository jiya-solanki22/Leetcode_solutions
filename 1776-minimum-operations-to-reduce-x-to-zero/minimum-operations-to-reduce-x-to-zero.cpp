class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int target = totalSum - x;
        if (target < 0)
            return -1;

        if (target == 0)
            return nums.size();

        int n = nums.size();
        int minOperations = INT_MAX;
        int currentSum = 0;
        int left = 0, right = 0;

        while (right < n) {
            currentSum += nums[right];
            right++;

            while (currentSum > target && left < n) {
                currentSum -= nums[left];
                left++;
            }

            if (currentSum == target)
                minOperations = min(minOperations, n - (right - left));
        }

        return (minOperations == INT_MAX) ? -1 : minOperations;
    }
};