class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inorder(numCourses,0);
        for(auto it: prerequisites){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
            inorder[u]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inorder[i]==0)
                q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;

            for(auto nbr:adj[node]){
                inorder[nbr]--;
                if(inorder[nbr]==0)
                    q.push(nbr);
            }
        }
        return cnt==numCourses;
    }
};
