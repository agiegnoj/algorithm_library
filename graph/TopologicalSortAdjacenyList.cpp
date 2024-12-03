#include <vector>
#include <queue>

using namespace std;

class TopologicalSortAdjacencyList{

    public:

    vector<int> sortedGraph(vector<vector<int>> adj, int numberOfNodes){
        
    vector<int> sortedGraph;
    vector<int> inDegree (numberOfNodes, 0);

    for (int i = 0 ;i< numberOfNodes; i++){
        for (int j = 0; j< adj[i].size(); j++){
            inDegree[adj[i][j]]++;
        }
    }

    queue<int> zeroEdgeNodes;

    for (int i = 0; i< numberOfNodes; i++){
        if (inDegree[i] == 0){
            zeroEdgeNodes.push(i);
        }
    }

    while (!zeroEdgeNodes.empty()){
        int n = zeroEdgeNodes.front();
        zeroEdgeNodes.pop();
        sortedGraph.push_back(n);

        for (int i = 0; i < adj[n].size(); i++){
            int neighbor = adj[n][i];
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0){
                zeroEdgeNodes.push(neighbor);
            }
        }
 
    }

    if (sortedGraph.size() != numberOfNodes)
    return {};

    return sortedGraph;

}

};

