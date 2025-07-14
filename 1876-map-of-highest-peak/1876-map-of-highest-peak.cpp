class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> height(m,vector<int>(n,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    height[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int delRow[]={-1,0,1,0};
        int delCol[]={0,-1,0,1};

        while(!q.empty()){
            auto [row,col]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && height[nrow][ncol]==-1){
                    height[nrow][ncol]=height[row][col]+1;
                    q.push({nrow,ncol});
                }
            }
        }
        return height;
    }
};