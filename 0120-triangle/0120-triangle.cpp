class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==1)
            return triangle[0][0];
        int m=triangle.size();
        vector<int> dp=triangle[0];
        vector<int> next_dp(m,INT_MAX);

        for(int i=1;i<m;i++){
            int n=triangle[i].size();
            for(int j=0;j<n;j++){
                int val=triangle[i][j];
                if(j==0){
                    next_dp[j]=dp[j]+val;
                }
                else if(j==n-1){
                    next_dp[j]=dp[j-1]+val;
                }
                else{
                    next_dp[j]=val+min(dp[j],dp[j-1]); 
                }
            }
            dp=next_dp;
        }
        int minSum= *min_element(dp.begin(),dp.end());

        return minSum;
    }
};