class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || i==(m-1) || j==0|| j==(n-1)) && grid[i][j]==1){
                    visited[i][j]=1;
                    q.push({i,j});
                }
                else if(grid[i][j]==0)
                    visited[i][j]=1;
            }
        }
        int delRow[]={-1,0,1,0};
        int delCol[]={0,-1,0,1};
        while(!q.empty()){
            auto[row,col]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1 && !visited[nrow][ncol]){
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        int count=0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==1 && visited[i][j]==0)
                count++;
            }
        }
        return count;
    }
};