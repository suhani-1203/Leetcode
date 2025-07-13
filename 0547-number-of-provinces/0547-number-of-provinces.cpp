class Solution {
private:
    void dfs(vector<int> adjLs[],vector<int>& vis,int node){
        vis[node]=1;

        for(auto it:adjLs[node]){
            if(!vis[it])
                dfs(adjLs,vis,it);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<int> adjLs[V];
        vector<int> vis(V,0);
        int count=0;

        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        } 
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                count++;
                dfs(adjLs,vis,i);
            }
        }
        return count;
    }
};