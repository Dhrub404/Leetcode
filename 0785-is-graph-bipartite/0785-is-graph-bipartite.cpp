class Solution {
public:
    bool res = true;
    void dfs(vector<vector<int>>& graph, vector<int>& color, int node, int c, bool &ans){
        color[node] = c;

        for(auto it : graph[node]){
            if(color[it] != -1 && color[it] == c){
                ans = false;
            }

            if(color[it] == -1){
                dfs(graph, color, it, 1-c, ans);
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        bool ans = true;

        for(int i=0;i<n;i++){
            if(color[i] == -1){
                dfs(graph, color, i, 0, ans);
            }
        }

        return ans;    
    }
};