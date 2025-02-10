import time

def dijkstra(graph, start):
    # Simple Dijkstra implementation
    import heapq
    queue = [(0, start)]
    distances = {node: float('inf') for node in graph}
    distances[start] = 0

    while queue:
        (cost, node) = heapq.heappop(queue)
        for neighbor, weight in graph[node].items():
            new_cost = cost + weight
            if new_cost < distances[neighbor]:
                distances[neighbor] = new_cost
                heapq.heappush(queue, (new_cost, neighbor))

    return distances

if __name__ == "__main__":
    graph = {
        'A': {'B': 1, 'C': 4},
        'B': {'C': 2, 'D': 5},
        'C': {'D': 1},
        'D': {}
    }

    start_time = time.time()
    dijkstra(graph, 'A')
    end_time = time.time()

    execution_time = (end_time - start_time) * 1000
    with open("result.txt", "w") as f:
        f.write(f"Execution time: {execution_time:.6f}\n")
