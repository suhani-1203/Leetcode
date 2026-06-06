class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return {0};

        vector<int> leftSum(n, 0);
        vector<int> rightSum(n, 0);
        vector<int> answer(n, 0);

        leftSum[0] = 0;
        rightSum[n - 1] = 0;

        for (int i = 1; i < n - 1; i++) {
            leftSum[i] = leftSum[i - 1] + nums[i - 1];
            rightSum[n - 1 - i] = rightSum[n - i] + nums[n - i];
        }
        leftSum[n - 1] = leftSum[n - 2] + nums[n - 2];
        rightSum[0] = rightSum[1] + nums[1];

        for (int i = 0; i < n; i++) {
            answer[i] = abs(leftSum[i] - rightSum[i]);
        }
        return answer;
    }
};
