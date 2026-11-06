class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        // Store queries as {query_time, original_index}
        vector<pair<int, int>> q(m);
        for (int i = 0; i < m; ++i) {
            q[i] = {queries[i], i};
        }
        
        // Sort queries by time
        sort(q.begin(), q.end());
        
        // Sort logs by time: logs[i][0] is server_id, logs[i][1] is time
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        vector<int> ans(m);
        unordered_map<int, int> server_count;
        
        int left = 0, right = 0;
        int l_size = logs.size();
        
        for (int i = 0; i < m; ++i) {
            int query_time = q[i].first;
            int idx = q[i].second;
            int window_start = query_time - x;
            int window_end = query_time;
            
            // Add logs that fall within the right boundary (<= window_end)
            while (right < l_size && logs[right][1] <= window_end) {
                server_count[logs[right][0]]++;
                right++;
            }
            
            // Remove logs that fall outside the left boundary (< window_start)
            while (left < l_size && logs[left][1] < window_start) {
                server_count[logs[left][0]]--;
                if (server_count[logs[left][0]] == 0) {
                    server_count.erase(logs[left][0]);
                }
                left++;
            }
            
            // Total servers minus servers that received at least one request = servers with zero requests
            ans[idx] = n - server_count.size();
        }
        
        return ans;
    }
};