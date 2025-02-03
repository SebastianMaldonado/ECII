#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <chrono>
#include <fstream>

using namespace std;

const int INF = numeric_limits<int>::max();

typedef pair<int, int> pii;

vector<int> dijkstra(int n, int start, vector<vector<pii>> &graph) {
    vector<int> dist(n, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &edge : graph[u]) {
            int v = edge.first, weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    ofstream output_file("results.txt");
    if (!output_file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }


    int n = 5;
    vector<vector<pii>> graph(n);
    graph[0].push_back({1, 10});
    graph[0].push_back({2, 3});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 2});
    graph[2].push_back({1, 4});
    graph[2].push_back({3, 8});
    graph[2].push_back({4, 2});
    graph[3].push_back({4, 7});
    graph[4].push_back({3, 9});

    auto start_time = chrono::high_resolution_clock::now();
    vector<int> distances = dijkstra(n, 0, graph);
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end_time - start_time;

    output_file << "Execution time: " << elapsed.count() << " seconds" << endl;
    output_file.close();

    while (true) {
        
    }

    return 0;
}