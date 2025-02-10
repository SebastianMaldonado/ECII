import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class code {

    public static Map<String, Integer> dijkstra(Map<String, Map<String, Integer>> graph, String start) {
        Map<String, Integer> distances = new HashMap<>();
        PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingInt(n -> n.distance));
        Set<String> visited = new HashSet<>();

        for (String node : graph.keySet()) {
            distances.put(node, Integer.MAX_VALUE);
        }
        distances.put(start, 0);
        pq.add(new Node(start, 0));

        while (!pq.isEmpty()) {
            Node current = pq.poll();
            if (visited.contains(current.name)) continue;
            visited.add(current.name);

            for (Map.Entry<String, Integer> neighbor : graph.get(current.name).entrySet()) {
                int newDist = current.distance + neighbor.getValue();
                if (newDist < distances.get(neighbor.getKey())) {
                    distances.put(neighbor.getKey(), newDist);
                    pq.add(new Node(neighbor.getKey(), newDist));
                }
            }
        }
        return distances;
    }

    public static void main(String[] args) throws IOException {
        Map<String, Map<String, Integer>> graph = new HashMap<>();
        graph.put("A", Map.of("B", 1, "C", 4));
        graph.put("B", Map.of("C", 2, "D", 5));
        graph.put("C", Map.of("D", 1));
        graph.put("D", Map.of());

        long startTime = System.nanoTime();
        dijkstra(graph, "A");
        long endTime = System.nanoTime();

        double executionTime = (endTime - startTime) / 1e6;
        try (FileWriter writer = new FileWriter("result.txt")) {
            writer.write(String.format("Execution time: %.6f%n", executionTime));
        }
    }

    static class Node {
        String name;
        int distance;

        Node(String name, int distance) {
            this.name = name;
            this.distance = distance;
        }
    }
}
