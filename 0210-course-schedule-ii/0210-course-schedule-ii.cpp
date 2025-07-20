class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> courseOrder;
        if(numCourses==1){
            courseOrder.push_back(0);
            return courseOrder;
        }
        vector<int> indegree(numCourses,0);
        for(auto it:prerequisites){
            int u=it[0],v=it[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            courseOrder.push_back(node);

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        if(courseOrder.size()!=numCourses){
            return {};
        }
        return courseOrder;
    }
};