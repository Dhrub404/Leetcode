class Solution {
public:

    void dfs_helper(vector<vector<int>>& adjList, vector<int> &vis, int node){
        vis[node] = 1;
        //traverse all its neighbours
        for(auto it : adjList[node]){
            if(!vis[it]){
                dfs_helper(adjList, vis, it);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adjList(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<int> vis(isConnected.size(), 0);
        int count = 0;

        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]){
                count++;
                dfs_helper(adjList, vis, i);
            }
        }

        return count;
    }
};