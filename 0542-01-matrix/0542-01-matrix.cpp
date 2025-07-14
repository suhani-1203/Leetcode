class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> distMat(m,vector<int>(n,-1));
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    distMat[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int delRow[]={-1,0,1,0};
        int delCol[]={0,-1,0,1};

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nrow=r+delRow[i];
                int ncol=c+delCol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n){
                    if(distMat[nrow][ncol]==-1){
                        distMat[nrow][ncol]=distMat[r][c]+1;
                        q.push({nrow,ncol});
                    }
                    
                } 
            }  
        }

        return distMat;
    }
};