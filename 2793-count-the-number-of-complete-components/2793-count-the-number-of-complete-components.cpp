class Solution {
public:
    void dfs(vector<vector<int>>& adjList,vector<int>& vis,int node,int& nodes,int& edges){
        vis[node]=1;
        nodes++;
        edges+=adjList[node].size();
        for(auto it:adjList[node]){
            if(vis[it]==-1)
                dfs(adjList,vis,it,nodes,edges);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int> vis(n,-1);
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                int nodes=0,edges=0;
                dfs(adjList,vis,i,nodes,edges);
                edges=edges/2;
                if((nodes*(nodes-1)/2)==edges)
                    count++;
            }
        }
        return count;
    }
};