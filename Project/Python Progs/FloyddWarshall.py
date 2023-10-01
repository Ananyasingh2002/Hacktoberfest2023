def fw(graph):
  n = len(graph)
  distances = [[float("inf")] * n for _ in range(n)]
  for i in range(n):
    for j in graph[i]:
      distances[i][j] = graph[i][j]
  for k in range(n):
    for i in range(n):
      for j in range(n):
        distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j])
  return distances
graph = [[0, 5, 10], [5, 0, 3], [10, 3, 0]]
distances = fw(graph)
for i in range(len(distances)):
  for j in range(len(distances[i])):
    print(f"Shortest distance from {i} to {j}: {distances[i][j]}")