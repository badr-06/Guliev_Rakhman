#include <iostream>

#include "libraries.h"

std::vector<int> bfs(std::vector<std::vector<int>> graph, int start) {
  std::vector<int> dist(graph.size(), INT_MAX);
  std::queue<int> q;

  dist[start] = 0;
  q.push(start);

  while (!q.empty()) {
    int v = q.front();
    q.pop();

    for (int to : graph[v]) {
      if (dist[to] > dist[v] + 1) {
        dist[to] = dist[v] + 1;
        q.push(to);
      }
    }
  }

  return dist;
}

int main() {
  int vertices_count, edges_count, start_vertix;
  std::ifstream fp("graph_1.txt");

  fp >> vertices_count;
  fp >> edges_count;

  std::vector<std::vector<int>> graph(vertices_count);
  int a, b;
  for (int i = 0; i < edges_count; ++i) {
    fp >> a;
    fp >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  fp >> start_vertix;

  fp.close();

  std::vector<int> dist = bfs(graph, start_vertix);

  for (int to : dist) {
    std::cout << to << std::endl;
  }

  return 0;
}