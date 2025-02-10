#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <fstream>
#include <chrono>

using namespace std;

void dijkstra(unordered_map<char, unordered_map<char, int>> &graph, char start) {
    unordered_map<char, int> distances;
    for (const auto &node : graph) {
        distances[node.first] = INT_MAX;
    }
    distances[start] = 0;

    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [currentDistance, node] = pq.top();
        pq.pop();

        for (const auto &neighbor : graph[node]) {
            int newDist = currentDistance + neighbor.second;
            if (newDist < distances[neighbor.first]) {
                distances[neighbor.first] = newDist;
                pq.push({newDist, neighbor.first});
            }
        }
    }
}

int main() {
    unordered_map<char, unordered_map<char, int>> graph = {
        {'A', {{'B', 1}, {'C', 4}}},
        {'B', {{'C', 2}, {'D', 5}}},
        {'C', {{'D', 1}}},
        {'D', {}}
    };

    auto start = chrono::high_resolution_clock::now();
    dijkstra(graph, 'A');
    auto end = chrono::high_resolution_clock::now();

    double executionTime = (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) / 1e6;
    ofstream file("result.txt");
    file << "Execution time: " << executionTime << "" << endl;
    file.close();

    return 0;
}
