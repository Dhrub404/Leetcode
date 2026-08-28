class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(n);
        vector<int> indegree(n, 0);
        queue<int> q;
        vector<int> ans;

        for(int i=0;i<prerequisites.size();i++){
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
          
        for(int i=0;i<n;i++){
            for(int it : adjList[i]){
                indegree[it]++;
            }
        }

        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int top = q.front();
            ans.push_back(top);
            q.pop();

            for(int it: adjList[top]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return ans.size() == n;
    }
};