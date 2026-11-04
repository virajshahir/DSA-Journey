class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        
        // Two multisets to maintain the lower and upper halves of the sliding window
        multiset<long long> low, high;
        long long low_sum = 0, high_sum = 0;

        auto balance = [&]() {
            int target_low = (x + 1) / 2;
            while (low.size() > target_low) {
                auto it = prev(low.end());
                long long val = *it;
                low.erase(it);
                low_sum -= val;
                high.insert(val);
                high_sum += val;
            }
            while (low.size() < target_low && !high.empty()) {
                auto it = high.begin();
                long long val = *it;
                high.erase(it);
                high_sum -= val;
                low.insert(val);
                low_sum += val;
            }
        };

        auto add = [&](long long val) {
            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                low_sum += val;
            } else {
                high.insert(val);
                high_sum += val;
            }
            balance();
        };

        auto remove = [&](long long val) {
            auto it = low.find(val);
            if (it != low.end()) {
                low.erase(it);
                low_sum -= val;
            } else {
                it = high.find(val);
                high.erase(it);
                high_sum -= val;
            }
            balance();
        };

        auto get_cost = [&]() {
            long long median = *low.rbegin();
            if (x % 2 == 1) {
                return high_sum - low_sum + median;
            } else {
                return high_sum - low_sum;
            }
        };

        for (int i = 0; i < x; ++i) {
            add(nums[i]);
        }

        vector<long long> cost;
        cost.push_back(get_cost());

        for (int i = x; i < n; ++i) {
            remove(nums[i - x]);
            add(nums[i]);
            cost.push_back(get_cost());
        }

        vector<long long> best(n + 1, 0);

        for (int j = 0; j < k; ++j) {
            vector<long long> layer(n + 1, LLONG_MAX / 2);
            for (int i = x; i <= n; ++i) {
                layer[i] = min(layer[i - 1], best[i - x] + cost[i - x]);
            }
            best = move(layer);
        }

        return best[n];
    }
};