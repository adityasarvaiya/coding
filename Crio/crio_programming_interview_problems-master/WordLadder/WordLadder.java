import java.io.*;
import java.util.*;

class WordLadder {
  // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
  public static boolean isValidTranformation(String a, String b) {
    int difference = 0;
    for (int i = 0; i < a.length(); ++i) {
      if (a.charAt(i) != b.charAt(i)) {
        difference++;
      }
    }
    return difference == 1;
  }
  // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

  public int ladderLength(String beginWord, String endWord, List<String> wordList) {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int n = wordList.size();
    Graph graph = new Graph(n + 1);
    int source = n;
    int destination = -1;

    for (int i = 0; i < wordList.size(); ++i) {
      for (int j = i + 1; j < wordList.size(); ++j) {
        if (isValidTranformation(wordList.get(i), wordList.get(j))) {
          graph.addEdge(i, j);
        }
      }
      if (isValidTranformation(beginWord, wordList.get(i))) {
        graph.addEdge(n, i);
      }
      if (wordList.get(i).equals(endWord)) {
        destination = i;
      }
    }
    return graph.shortestPath(source, destination);
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    String beginWord = scanner.nextLine();
    String endWord = scanner.nextLine();

    int n = scanner.nextInt();
    List<String> wordList = new ArrayList<String>();

    for (int i = 0; i < n; ++i) {
      String word = scanner.next();
      wordList.add(word);
    }
    scanner.close();
    int result = new WordLadder().ladderLength(beginWord, endWord, wordList);
    System.out.println(result);
  }
}

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
class Graph {
  private int n;
  private int adj[][];

  Graph(int n) {
    this.n = n;
    this.adj = new int[n][n];
  }

  public void addEdge(int u, int v) {
    this.adj[u][v] = 1;
    this.adj[v][u] = 1;
  }

  public int shortestPath(int source, int destination) {
    boolean visited[] = new boolean[this.n];
    int distance[] = new int[this.n];

    LinkedList<Integer> queue = new LinkedList<Integer>();

    visited[source] = true;
    distance[source] = 1;
    queue.add(source);
    while (queue.size() != 0) {
      int current = queue.poll();

      if (current == destination) {
        return distance[current];
      }

      for (int i = 0; i < n; ++i) {
        int nextVertex = i;
        if (this.adj[current][nextVertex] == 1 && !visited[nextVertex]) {
          visited[nextVertex] = true;
          distance[nextVertex] = distance[current] + 1;
          queue.add(nextVertex);
        }
      }
    }
    return 0;
  }
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
