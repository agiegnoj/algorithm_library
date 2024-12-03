#include <vector>
#include <climits>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

class DijkstraAdjacencyMatrix{

    map<int, int> predecessors;
    vector<int> distances;

    public:
    
    DijkstraAdjacencyMatrix(vector<vector<int>>& graph, int src){
        shortestPathsFromSource(graph, src);
    }

   void shortestPathsFromSource(vector<vector<int>>& graph, int src){
        int n = graph.size();
        distances.assign(n, INT_MAX);
        set<int> explored;
        
        auto compare = [&](int a, int b) { return distances[a] > distances[b]; };
        priority_queue<int, vector<int>, decltype(compare)> pq(compare);
        pq.push(src); 

        distances[src] = 0;

        while (!pq.empty()){

            int vertex = pq.top();
            pq.pop();

            explored.insert(vertex);

            for (int i = 0; i < graph.size(); i++){
                if (graph[vertex][i] != 0 && explored.find(i) == explored.end()) { 
                int minDistance = distances[vertex] + graph[vertex][i];
                if (minDistance < distances[i]) {
                    pq.push(i);
                    distances[i] = minDistance;
                    predecessors[i] = vertex;
                    
                }
            }
            }

        }
    }

    vector<int> getshortestPathFromSourceToVertex(int src, int end){

        int current = end;
        vector<int> path;

        if (src == end){
            return{src};
        }

        while (current != src){
            if (predecessors.find(current) == predecessors.end()) {
                return {};
            }
            path.push_back(current);
            current = predecessors[current];
        }
        
        reverse(path.begin(), path.end());

        return path;

    }

    int getShortestPathLength(int end){
        return distances [end];
    }

};




