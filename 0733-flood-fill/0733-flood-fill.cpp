class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int oldColor=image[sr][sc];

        if(oldColor==color)
            return image;
            
        image[sr][sc]=color;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int delRow[]={-1,0,1,0};
        int delCol[]={0,-1,0,1};

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=r+delRow[i];
                int ncol=c+delCol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol]==oldColor){
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
        return image;
    }
};