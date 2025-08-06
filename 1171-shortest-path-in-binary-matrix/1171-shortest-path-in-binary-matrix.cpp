class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0]=1;
        int delRow[]={-1,-1,-1,0,0,1,1,1};
        int delCol[]={-1,0,1,1,-1,0,1,-1};

        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});

        while(!q.empty()){
            int d=q.front().first;
            auto[u,v]=q.front().second;
            q.pop();
            if(u==n-1 && v==n-1)
                return d;
            for(int i=0;i<8;i++){
                int nrow=u+delRow[i];
                int ncol=v+delCol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && d+1<dist[nrow][ncol]){
                    dist[nrow][ncol]=d+1;
                    q.push({dist[nrow][ncol],{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};