#include <vector>
#include <climits>
#include <cmath>
#include <iostream>
using namespace std;

template <typename T>
class ShortestPathInMazeDFSAndManhattanDistance {
public:
    const vector<vector<T>> maze;
    const T blockingObject;
    vector<pair<int, int>> shortestPath;
    const int destinationX;
    const int destinationY;

    ShortestPathInMazeDFSAndManhattanDistance(vector<vector<T>> m, T obj, int startX, int destX, int startY, int destY)
        : maze(m), blockingObject(obj), destinationX(destX), destinationY(destY) {
            
        vector<pair<int, int>> path;
        vector<vector<long>> memoization(maze.size(), vector<long>(maze[0].size(), LONG_MAX));
        dfs(startX, startY, path, memoization, 0);
    }

    vector<pair<int, int>> getShortestPath() {
        return shortestPath;
    }

    long getShortestPathLength() {
        return shortestPath.empty() ? -1 : shortestPath.size();
    }

private:
    void dfs(int currentX, int currentY, vector<pair<int, int>>& path, vector<vector<long>>& memoization, long steps) {
        // Check bounds and blocking object
        if (currentX < 0 || currentX >= maze.size() || currentY < 0 || currentY >= maze[0].size() ||
            maze[currentX][currentY] == blockingObject) {
            return;
        }

        // Avoid revisiting nodes or taking longer paths
        if (memoization[currentX][currentY] <= steps || manhattanDistance(currentX, currentY) + steps >= memoization[destinationX][destinationY]) {
            return;
        }

        // Update memoization
        memoization[currentX][currentY] = steps;

        // Add current cell to the path
        path.emplace_back(currentX, currentY);

        // If destination is reached, update the shortest path
        if (currentX == destinationX && currentY == destinationY) {
            if (shortestPath.empty() || path.size() < shortestPath.size()) {
                shortestPath = path;  // Update shortest path
            }
        } else {
            // Explore all four directions
            dfs(currentX + 1, currentY, path, memoization, steps + 1);
            dfs(currentX - 1, currentY, path, memoization, steps + 1);
            dfs(currentX, currentY + 1, path, memoization, steps + 1);
            dfs(currentX, currentY - 1, path, memoization, steps + 1);
        }

        // Backtrack (remove the last element to explore other paths)
        path.pop_back();
    }

    long manhattanDistance(int x, int y) {
        return abs(destinationX - x) + abs(destinationY - y);
    }
};




  
