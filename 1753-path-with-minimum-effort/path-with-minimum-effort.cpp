class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int left = 0, right = INT_MAX;
        int result = 0;
        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
            queue<pair<int, int>> q;
            q.push({0, 0});
            visited[0][0] = true;
            while (!q.empty()) 
            {
                auto [x, y] = q.front();
                q.pop();
                for (auto& dir : directions) {
                    int newX = x + dir[0];
                    int newY = y + dir[1];
                    if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && !visited[newX][newY] && abs(heights[x][y] - heights[newX][newY]) <= mid) 
                    {
                        q.push({newX, newY});
                        visited[newX][newY] = true;
                    }
                }
            }
            if (visited[rows - 1][cols - 1]) 
            {
                right = mid - 1;
                result = mid;
            } 
            else 
            {
                left = mid + 1;
            }
        }
        return result;
    }
};