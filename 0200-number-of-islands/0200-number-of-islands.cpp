class Solution {
private:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& visited,int row,int col,int n,int m){
        visited[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});

        int delRow[]={-1,0,1,0};
        int delCol[]={0,-1,0,1};

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

                for(int k=0;k<4;k++){
                    int neighRow=row+delRow[k];
                    int neighCol=col+delCol[k];
                    if(neighRow>=0 && neighRow<n && neighCol>=0 && neighCol<m && grid[neighRow][neighCol]=='1' && !visited[neighRow][neighCol]){
                        visited[neighRow][neighCol]=1;
                        q.push({neighRow,neighCol});
                    }
                }
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;

        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(grid,visited,i,j,n,m);
                }
            }
        }
        return count;
    }
};