class Solution {
public:
    void dfs(int currRoom, vector<vector<int>>& rooms, vector<bool>& visited) {
        visited[currRoom] = true;

        for (int keys : rooms[currRoom]) {
            if (visited[keys] == false) {
                dfs(keys, rooms, visited);
            }
        }

        return;
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        dfs(0, rooms, visited);

        for (bool room : visited) {
            if (!room) return false;
        }
        return true;
    }
};