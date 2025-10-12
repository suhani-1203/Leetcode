

typedef long long ll;

const int MOD = 1e9 + 7;

// Global arrays for precomputed factorials and modular inverse
// Must be global or static members if helper functions are outside the class
ll fact[31]; 
ll invFact[31]; 


class Solution {
private:
    // --- Modular Arithmetic Helpers ---
    
    // Modular exponentiation
    ll power(ll base, ll exp) {
        ll res = 1; base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD; exp /= 2;
        }
        return res;
    }

    // Modular inverse using Fermat's Little Theorem
    ll modInverse(ll n) { return power(n, MOD - 2); }

    // Precompute factorials and their modular inverses
    void precompute(int max_m) {
        fact[0] = 1;
        for (int i = 1; i <= max_m; i++) fact[i] = (fact[i - 1] * i) % MOD;
        invFact[max_m] = modInverse(fact[max_m]);
        for (int i = max_m - 1; i >= 0; i--) invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }

    // Binomial coefficient C(n, k)
    ll nCr_mod(int n, int r) {
        if (r < 0 || r > n) return 0;
        return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
    }

    // Function to count set bits (popcount)
    int countSetBits(int n) {
        int count = 0;
        while (n > 0) { n &= (n - 1); count++; }
        return count;
    }

public:
    /**
     * @brief Calculates the sum of array products for all magical sequences.
     * The DP state is DP[i][j][C_i][set_bits].
     */
    int magicalSum(int m, int k, vector<int>& nums) { // Renamed to magicalSum
        int N = nums.size();
        if (k > m) return 0;

        precompute(m);

        // DP[i][j][C_i][set_bits]
        // i: index (0 to N) | j: total indices used (0 to m)
        // C_i: carry to bit i (0 to m) | set_bits: total set bits found (0 to k)
        vector<vector<vector<vector<ll>>>> dp(N + 1, 
            vector<vector<vector<ll>>>(m + 1, 
                vector<vector<ll>>(m + 1, 
                    vector<ll>(k + 1, 0))));

        dp[0][0][0][0] = 1; // Base case

        for (int i = 0; i < N; ++i) {
            // Precompute powers of nums[i]
            vector<ll> powers_ni(m + 1);
            powers_ni[0] = 1;
            for(int c = 1; c <= m; ++c) powers_ni[c] = (powers_ni[c-1] * (ll)nums[i]) % MOD;

            for (int j = 0; j <= m; ++j) {
                for (int C_i = 0; C_i <= m; ++C_i) {
                    for (int set_bits = 0; set_bits <= k; ++set_bits) {
                        if (dp[i][j][C_i][set_bits] == 0) continue;

                        ll current_value = dp[i][j][C_i][set_bits];

                        // Transition: Iterate over c_i (count of index i)
                        for (int c_i = 0; c_i <= m - j; ++c_i) {
                            int j_prime = j + c_i; 
                            
                            // Binary addition logic
                            int V_i = C_i + c_i;
                            int C_i_plus_1 = V_i / 2;      // New carry
                            int bit_i = V_i % 2;           // Set bit at position i
                            int set_bits_prime = set_bits + bit_i;

                            if (set_bits_prime > k || C_i_plus_1 > m) continue;

                            // Factor = C(j_prime, c_i) * (nums[i])^c_i
                            ll arrangements_factor = nCr_mod(j_prime, c_i);
                            ll product_factor = powers_ni[c_i];
                            
                            ll transition_value = (current_value * arrangements_factor) % MOD;
                            transition_value = (transition_value * product_factor) % MOD;

                            // Update next DP state
                            dp[i + 1][j_prime][C_i_plus_1][set_bits_prime] = 
                                (dp[i + 1][j_prime][C_i_plus_1][set_bits_prime] + transition_value) % MOD;
                        }
                    }
                }
            }
        }

        ll total_sum = 0;
        // Final Answer: Sum DP[N][m][C_N][set_bits] where set_bits + popcount(C_N) = k
        for (int C_N = 0; C_N <= m; ++C_N) {
            int popcount_C_N = countSetBits(C_N);
            int required_set_bits = k - popcount_C_N;

            if (required_set_bits >= 0 && required_set_bits <= k) {
                total_sum = (total_sum + dp[N][m][C_N][required_set_bits]) % MOD;
            }
        }

        return (int)total_sum;
    }
};


