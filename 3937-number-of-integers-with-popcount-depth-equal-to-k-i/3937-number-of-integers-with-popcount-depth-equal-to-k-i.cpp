const long long mod = 1e9 + 7, MX = 2e5 + 5;
const long long INF = 1e18;

// __builtin_popcount(x) → counts number of set bits in x
constexpr long long pct(int x) { return __builtin_popcount(x); }

// __builtin_clz(x) → counts leading zeros
// 31 - clz(x) gives the position of the highest set bit
constexpr long long bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }

int dx[4] = {0, 1, 0, -1}; // direction helpers (not used here)
int dy[4] = {-1, 0, 1, 0};

class Solution {
public:
    string s; // binary representation of n (without leading zeros)
    long long cnt[66]; // cnt[i] = popcount-depth of i
    long long dp[64][64][2]; // digit DP memo table

    // DP to count how many numbers <= n have exactly `lim` ones
    long long rec(int idx, int lim, int tight) {
        if (lim < 0) return 0; // can't have negative set bits
        if (idx >= s.length() && lim == 0) return 1LL; // perfect match
        if (idx >= s.length()) return 0; // overflow
        if (dp[idx][lim][tight] != -1) return dp[idx][lim][tight];

        int limit = tight ? s[idx] - '0' : 1;
        long long num_cnt = 0;
        for (int i = 0; i <= limit; ++i) {
            num_cnt += rec(idx + 1, lim - i, tight && (i == limit));
        }

        return dp[idx][lim][tight] = num_cnt;
    }

    long long popcountDepth(long long n, int k) {
        if (k == 0) return 1; // only x=1 has depth 0

        memset(cnt, 0, sizeof(cnt));
        cnt[1] = 0;

        // Precompute popcount-depth for all i from 2 to 64
        for (int i = 2; i <= 64; ++i)
            cnt[i] = cnt[pct(i)] + 1;

        // Convert n to binary string s (no leading zeros)
        int flag = 0;
        for (long long i = 62; i >= 0; --i) {
            if ((n >> i) & 1LL) flag = 1;
            if (flag) s.push_back(((n >> i) & 1LL) + '0');
        }

        long long ans = 0;

        // Try every possible number of set bits `i`
        for (int i = 1; i <= 62; ++i) {
            if (cnt[i] == k - 1) {
                memset(dp, -1, sizeof(dp));
                ans += rec(0, i, 1);
                if (i == 1) --ans; // exclude x=1 if it's overcounted
            }
        }

        return ans;
    }
};












