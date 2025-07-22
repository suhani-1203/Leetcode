class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        arr.push_back(0);  // sentinel to flush stack at end
        stack<pair<int, int>> st;  // pair: (value, count)
        long long res = 0, cur = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i <= n; ++i) {
            int val = (i < n) ? arr[i] : 0;
            int count = 1;

            while (!st.empty() && st.top().first >= val) {
                auto [prevVal, prevCount] = st.top();
                st.pop();
                count += prevCount;
                cur -= 1LL * prevVal * prevCount;
            }

            st.emplace(val, count);
            cur += 1LL * val * count;
            res = (res + cur) % mod;
        }

        return res;
    }
};
