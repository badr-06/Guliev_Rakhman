#include <gtest/gtest.h>

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

TEST(graph_1_txt, test1) {
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

  std::vector<int> res{1, 2, 3, 3, 0};

  for (int i = 0; i < vertices_count; ++i) {
    EXPECT_EQ(res[i], dist[i]);
  }
}

TEST(graph_2_txt, test2) {
  int vertices_count, edges_count, start_vertix;
  std::ifstream fp("graph_2.txt");

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

  std::vector<int> res{2, 3, 1, 2, 1, 0};

  for (int i = 0; i < vertices_count; ++i) {
    EXPECT_EQ(res[i], dist[i]);
  }
}

TEST(graph_3_txt, test3) {
  int vertices_count, edges_count, start_vertix;
  std::ifstream fp("graph_3.txt");

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

  std::vector<int> res{5, 4, 3, 2, 1, 0, 1, 2, 3, 4};

  for (int i = 0; i < vertices_count; ++i) {
    EXPECT_EQ(res[i], dist[i]);
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
