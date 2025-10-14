class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Iterate through all possible starting indices 'a' for the first subarray.
        // The first subarray ends at a + k - 1.
        // The second subarray starts at b = a + k and ends at a + 2*k - 1.
        // We must ensure a + 2*k - 1 < n, so a <= n - 2*k.
        for (int a = 0; a <= n - 2 * k; ++a) {
            int b = a + k;

            // 1. Check if the first subarray nums[a..a + k - 1] is strictly increasing.
            bool first_increasing = true;
            for (int i = 0; i < k - 1; ++i) {
                if (nums[a + i] >= nums[a + i + 1]) {
                    first_increasing = false;
                    break;
                }
            }

            if (first_increasing) {
                // 2. If the first is strictly increasing, check the second adjacent subarray nums[b..b + k - 1].
                bool second_increasing = true;
                for (int i = 0; i < k - 1; ++i) {
                    // b + i is the current element, b + i + 1 is the next
                    if (nums[b + i] >= nums[b + i + 1]) {
                        second_increasing = false;
                        break;
                    }
                }

                if (second_increasing) {
                    // Found two strictly increasing and adjacent subarrays of length k
                    return true;
                }
            }
        }

        return false;
    }
};

