class Solution {
public:
    bool dfs(int node,int setNo,vector<vector<int>>& graph,vector<int>& vis){
        vis[node]=setNo;

        for(auto it:graph[node]){
            if(vis[it]==-1){
                if(dfs(it,!setNo,graph,vis)==false)
                    return false;
            }
            else if(vis[it]==setNo)
                return false;
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> vis(V,-1);
        
        
        for(int i=0;i<V;i++){
            if(vis[i]==-1){
                if(dfs(i,0,graph,vis)==false)
                    return false;
            }
        }
        return true;
    }
};