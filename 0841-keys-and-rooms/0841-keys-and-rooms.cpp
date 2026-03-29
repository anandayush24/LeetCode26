class Solution {
public:
    void dfs(vector<vector<int>> &rooms, vector<int> &visited, int roomNumber) {
        if(visited[roomNumber] == 1) { return; }
        visited[roomNumber] = 1;
        for(int key: rooms[roomNumber]) {
            dfs(rooms, visited, key);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int noOfRooms = rooms.size();
        vector<int> visited(noOfRooms, 0);
        dfs(rooms, visited, 0);
        for(int key: visited) {
            if(key == 0) {
                return false;
            }
        }
        return true;
    }
};
/*
Intution: DFS
1. Make a visited array, with room[0] -> visited
2. keep visiting the rooms whose keys are found
3. Check the visited array, if all the rooms are visited, return true, else false

Next steps:
-> Explain why no visited → infinite loop
-> Convert this to BFS on the spot

Time complexity: O(v+e)
v -> number of rooms
e -> number of keys across rooms
*/