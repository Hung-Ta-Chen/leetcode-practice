# DFS Solution (TLE)
# we start from node 0 and try all possible paths.
# Also, since cycle exists in some cases, 
# we have to record which path has been visited.

class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        shortest_path = [500] * n
        shortest_path[0] = 0
        path_visited = [[0]*len(redEdges), [0]*len(blueEdges)]

        def dfs(node, color, depth):
            if depth < shortest_path[node]:
                shortest_path[node] = depth
            if color == 1:    # Find red edge
                for i, ls in enumerate(redEdges):
                    if ls[0] == node and path_visited[0][i] == 0:
                        path_visited[0][i] = 1
                        dfs(ls[1], color*(-1), depth+1)
                        path_visited[0][i] = 0
            else:   # Find blue edge
                for i, ls in enumerate(blueEdges):
                    if ls[0] == node and path_visited[1][i] == 0:
                        path_visited[1][i] = 1
                        dfs(ls[1], color*(-1), depth+1)
                        path_visited[1][i] = 0

        dfs(0, 1, 0)  # Start from red edge
        dfs(0, -1, 0) # Start from blue edge
        for i in range(len(shortest_path)):
            if shortest_path[i] == 500:
                shortest_path[i] = -1
        return shortest_path
