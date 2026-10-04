class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //topological sort method

        int n = graph.size();

        vector<vector<int>> adjList(n);
        vector<int> ans;
        vector<int> indegree(n);
        queue<int> q;

        for(int i=0;i<n;i++){
            for(auto it : graph[i]){
                adjList[it].push_back(i);
                indegree[i]++;
            }
        }

        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int top = q.front();
            q.pop();
            ans.push_back(top);

            for(auto it : adjList[top]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};






//dfs
// class Solution {
// public:

//     bool dfs(vector<vector<int>>& graph, vector<int>& vis, vector<int> &pathVis, vector<int> &check, int node){
//         vis[node] = 1;
//         pathVis[node] = 1;

//         for(auto it : graph[node]){
//             if(!vis[it]){
//                 if(dfs(graph,vis,pathVis,check,it) == true){
//                     return true;
//                 }
//             }

//             else if(pathVis[it] == 1){
//                 return true;
//             }
//         }

//         check[node] = 1;
//         pathVis[node] = 0;

//         return false;
//     }

//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n = graph.size();

//         vector<int> pathVis(n, 0);
//         vector<int> ans;
//         vector<int> check(n, 0);
//         vector<int> vis(n, 0);

//         for(int i=0;i<n;i++){
//             if(!vis[i]){
//                 dfs(graph, vis, pathVis, check, i);
//             }
//         }

//         for(int i=0;i<n;i++){
//             if(check[i] == 1)   ans.push_back(i);
//         }

//         return ans;
//     }
// };