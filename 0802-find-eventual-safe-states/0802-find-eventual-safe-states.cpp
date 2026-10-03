class Solution {
public:

    bool dfs(vector<vector<int>>& graph, vector<int>& vis, vector<int> &pathVis, vector<int> &check, int node){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfs(graph,vis,pathVis,check,it) == true){
                    return true;
                }
            }

            else if(pathVis[it] == 1){
                return true;
            }
        }

        check[node] = 1;
        pathVis[node] = 0;

        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> pathVis(n, 0);
        vector<int> ans;
        vector<int> check(n, 0);
        vector<int> vis(n, 0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(graph, vis, pathVis, check, i);
            }
        }

        for(int i=0;i<n;i++){
            if(check[i] == 1)   ans.push_back(i);
        }

        return ans;
    }
};