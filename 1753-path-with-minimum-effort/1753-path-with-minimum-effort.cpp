class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        int min_effort=INT_MAX;
        int delRow[]={-1,0,0,1};
        int delCol[]={0,1,-1,0};
        vector<vector<int>> effort(n,vector<int>(m,1e9));
        effort[0][0]=0;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int, pair<int,int>>>> pq;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int diff=pq.top().first;
            auto[row,col]=pq.top().second;
            pq.pop();

            for(int i=0;i<4;i++){
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                    int newEffort=max(abs(heights[row][col]-heights[nrow][ncol]),diff);

                    if(newEffort<effort[nrow][ncol]){
                        effort[nrow][ncol]=newEffort;
                        pq.push({newEffort,{nrow,ncol}});
                    }
                }
            }
        }
        return effort[n-1][m-1];
    }
};