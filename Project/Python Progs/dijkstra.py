import sys

def minDistance(visited, dist):
    min_index = 0
    min = sys.maxsize

    for i in range(len(visited)):
        if visited[i]==False and dist[i] < min:
            min = dist[i]
            min_index = i

    return min_index

def dijkstra(graph, src):
    visited = []
    dist = []
    
    v = len(graph);

    for i in range(v):
        visited.append(False)
        dist.append(sys.maxsize)

    dist[src] = 0

    for i in range(v-1):
        u = minDistance(visited, dist)  
        visited[u] = True

        for j in range(v):
            edge_weight = graph[u][j]
            new_weight = dist[u] + edge_weight

            if (graph[u][j] > 0 and dist[u] < sys.maxsize and new_weight < dist[j] and visited[j] == False):
                dist[j] = new_weight

    print("Distance of each vertex from the source is: ");
    print(f"Vertex\tMinimum Distance from Vertex {src}")
    for i  in range(v):
        print(f"{i}\t\t\t{dist[i]}")


# graph = [ [ 0, 4, 0, 0, 0, 0, 0, 8, 0 ],
#                         [ 4, 0, 8, 0, 0, 0, 0, 11, 0 ],
#                         [ 0, 8, 0, 7, 0, 4, 0, 0, 2 ],
#                         [ 0, 0, 7, 0, 9, 14, 0, 0, 0 ],
#                         [ 0, 0, 0, 9, 0, 10, 0, 0, 0 ],
#                         [ 0, 0, 4, 14, 10, 0, 2, 0, 0 ],
#                         [ 0, 0, 0, 0, 0, 2, 0, 1, 6 ],
#                         [ 8, 11, 0, 0, 0, 0, 1, 0, 7 ],
#                         [ 0, 0, 2, 0, 0, 0, 6, 7, 0 ] ]

graph = [[0, 3, 1, 0, 0],
         [3, 0, 1, 3, 1],
         [1,1, 0, 0, 4],
         [0, 3, 0, 0, 2],
         [0, 1, 4, 2, 0]]

if __name__ == "__main__":

    dijkstra(graph, 0)



