class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_val = nums[0];
        long long sum = 0;

        for (int num : nums) {
            sum += num;
            if (num < min_val) {
                min_val = num;
            }
        }
        return sum - (long long)nums.size() * min_val;
    }
};
