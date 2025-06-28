class Solution {
public:
    int climbStairs(int n){
        if(n==1) return 1;
        if(n==2) return 2;
        vector<int> dp(n+1);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};


















/*int climbStairs(int n) {
        if(n<=3)
            return n;
        int prev1=3;
        int prev2=2;
        int curr=0;

        for(int i=3;i<n;i++){
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return curr;*/