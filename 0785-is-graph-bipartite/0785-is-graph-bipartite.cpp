class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        int c = 0;

        queue<int> q;

        for(int i=0;i<n;i++){
            if(color[i] != -1)  continue;

            color[i] = 0;
            q.push(i);

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(auto it : graph[node]){
                    if(color[it] == -1){
                        color[it] = 1 - color[node];
                        q.push(it);
                    }
                    else if(color[it] == color[node]){
                        return false;
                    }
                }
            }
        }

        return true;
    }
};


//dfs
// class Solution {
// public:

//     void dfs(vector<vector<int>>& graph, vector<int>& color, int node, int c, bool &ans){
//         color[node] = c;

//         for(auto it : graph[node]){
//             if(color[it] != -1 && color[it] == c){
//                 ans = false;
//             }

//             if(color[it] == -1){
//                 dfs(graph, color, it, 1-c, ans);
//             }
//         }
//     }

//     bool isBipartite(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> color(n, -1);
//         bool ans = true;

//         for(int i=0;i<n;i++){
//             if(color[i] == -1){
//                 dfs(graph, color, i, 0, ans);
//             }
//         }

//         return ans;    
//     }
// };