const dijkstra = (graph, start) => {
    let distances = {};
    let priorityQueue = [[start, 0]];
  
    for (let node in graph) {
      distances[node] = Infinity;
    }
    distances[start] = 0;
  
    while (priorityQueue.length > 0) {
      let [currentNode, currentDist] = priorityQueue.shift();
  
      for (let neighbor in graph[currentNode]) {
        let newDist = currentDist + graph[currentNode][neighbor];
        if (newDist < distances[neighbor]) {
          distances[neighbor] = newDist;
          priorityQueue.push([neighbor, newDist]);
        }
      }
  
      priorityQueue.sort((a, b) => a[1] - b[1]);
    }
  
    return distances;
  };
  
  const graph = {
    A: { B: 1, C: 4 },
    B: { C: 2, D: 5 },
    C: { D: 1 },
    D: {}
  };
  
  // Use process.hrtime for high-resolution timing
  const startTime = process.hrtime();
  dijkstra(graph, "A");
  const endTime = process.hrtime(startTime);
  
  const executionTime = (endTime[0] * 1000) + (endTime[1] / 1e6);
  
  const fs = require("fs");
  fs.writeFileSync("result.txt", `Execution time: ${executionTime.toFixed(6)}\n`);
  