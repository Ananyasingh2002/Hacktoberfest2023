def dijkstra_algorithm(graph, source_ver):
  dist = {}
  for ver in graph:
    dist[ver] = float("inf")
  dist[source_ver] = 0
  visited = set()
  while visited != set(graph):
    current_ver = min(dist, key=dist.get)
    visited.add(current_ver)
    for neighbor in graph[current_ver]:
      if neighbor not in visited:
        new_dist = dist[current_ver] + graph[current_ver][neighbor]
        if new_dist < dist[neighbor]:
          dist[neighbor] = new_dist

  return dist
