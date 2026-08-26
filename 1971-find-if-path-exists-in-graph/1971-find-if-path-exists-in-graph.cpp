class Solution {
public:

    void bfs(vector<vector<int>> &adj, vector<bool> &visited, int node){
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while(!q.empty()){
            int frontVertex = q.front();
            q.pop();

            // traverse all neighbours 1st way is using auto keyword
            // for(auto neighbour : adj[frontVertex]){
            //     if(!visited[neighbour]){
            //         visited[neighbour] = true;
            //         q.push(neighbour);
            //     }
            // }
            
            // Visit all neighbours of frontVertex using normal loop
            for(int i=0;i<adj[frontVertex].size();i++){
                int neighbour = adj[frontVertex][i];
                //if neighbour is not visited
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjList(n);

        for(int i=0;i<edges.size();i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> vis(n, false);

        bfs(adjList, vis, source);

        return vis[destination];
    }
};