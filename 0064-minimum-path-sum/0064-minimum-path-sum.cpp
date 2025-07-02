class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                int right=0,down =0;
                if(i==0){
                    dp[i][j]=dp[i][j-1]+grid[i][j];
                    continue;
                }
                else if(j==0){
                    dp[i][j]=dp[i-1][j]+grid[i][j];
                    continue;
                } 
                else{
                    right=dp[i][j-1]+grid[i][j];
                    down=dp[i-1][j]+grid[i][j];
                    dp[i][j]= min(right,down);
                }
            }
        }
        return dp[m-1][n-1];
    }
};