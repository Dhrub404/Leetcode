class Solution {
public:

    void dfs(int room, vector<vector<int>>& rooms, vector<bool>& visited) {
        visited[room] = true;

        for(int it : rooms[room]){
            if (!visited[it])
                dfs(it, rooms, visited);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        dfs(0, rooms, visited);

        for(auto it : visited){
            if(it == false)
                return false;
        }

        return true;
    }
};