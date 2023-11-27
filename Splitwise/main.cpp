#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdexcept>

using namespace std;

class Graph {
public:
    unordered_map<string, unordered_map<string, double>> adjList;

    void addEdge(const string& from, const string& to, double weight) {
        adjList[from][to] = weight;
    }
};

double round(double value, int places) {
    if (places < 0) {
        throw invalid_argument("places must be non-negative");
    }

    double multiplier = pow(10.0, places);
    return round(value * multiplier) / multiplier;
}

void findPath(Graph& graph, const string& currentNode, double currentDebt) {
    for (const auto& neighbor : graph.adjList[currentNode]) {
        const string& nextNode = neighbor.first;
        double nextDebt = neighbor.second;

        double result = currentDebt + nextDebt;
        result = round(result, 1);

        if (result >= 0.0) {
            cout << currentNode << " needs to pay " << nextNode << ": " << round(abs(nextDebt), 2) << endl;
            graph.adjList[currentNode].erase(nextNode);
            findPath(graph, nextNode, result);
            return;
        }
        else {
            cout << currentNode << " needs to pay " << nextNode << ": " << round(abs(currentDebt), 2) << endl;
            graph.adjList[currentNode].erase(nextNode);
            findPath(graph, nextNode, result);
            return;
        }
    }
}

int main() {
    Graph graph;

    graph.addEdge("A", "B", -5.0);
    graph.addEdge("B", "D", 25.0);
    graph.addEdge("D", "B", -25.0);
    graph.addEdge("C", "B", -20.0);
    graph.addEdge("D", "C", 25.0);
    graph.addEdge("E", "C", -20.0);
    graph.addEdge("F", "E", -5.0);

    string startNode = "B";  // Starting from B to simplify the example, you can change it as needed
    double startDebt = 0.0;

    findPath(graph, startNode, startDebt);

    return 0;
}
