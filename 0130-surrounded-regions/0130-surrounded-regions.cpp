class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> visited(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0||i==m-1||j==0||j==n-1) && board[i][j]=='O'){
                    visited[i][j]=1;
                    q.push({i,j});
                }
                else if(board[i][j]=='X')
                    visited[i][j]=1;
            }
        }
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        while(!q.empty()){
            auto[row,col]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol] && board[nrow][ncol]=='O'){
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(board[i][j]=='O' &&  !visited[i][j])
                    board[i][j]='X';
            }
        }
    }
};