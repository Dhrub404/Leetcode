class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        vector<int> ans;

        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int top = q.front();
            ans.push_back(top);
            q.pop();

            for(int it: adj[top]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return ans.size() == n;
    }
};