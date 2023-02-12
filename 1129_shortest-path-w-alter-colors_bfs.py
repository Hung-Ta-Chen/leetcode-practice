# ps: In Python, if we want to initialize a list of n empty lists, we have to use list comprehension to avoid same reference 
class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        adj_list = [[] for i in range(n)]
        for ls in redEdges:
            adj_list[ls[0]].append((ls[1], 0))
        for ls in blueEdges:
            adj_list[ls[0]].append((ls[1], 1))
        
        shortest_path = [500] * n
        shortest_path[0] = 0
        # Important Part: one node can be visited at most twice(1 from red edge, 1 from blue edge)
        visited = [[0, 0] for i in range(n)] 
        visited[0][0] = visited[0][1] = 1
        
        q = collections.deque()
        q.append((0, 0, -1))  # Set the color of init to -1 so that it's different from both 0 and 1

        while q:
            size = len(q)
            for i in range(size):
                front = q.popleft()
                node, depth, color = front[0], front[1], front[2]
                if depth < shortest_path[node]:
                    shortest_path[node] = depth
                for nb in adj_list[node]:
                    # If color alters, we push it into queue
                    if color != nb[1] and visited[nb[0]][nb[1]] == 0:
                        q.append((nb[0], depth+1, nb[1]))
                        visited[nb[0]][nb[1]] = 1

        for i in range(len(shortest_path)):
            if shortest_path[i] == 500: shortest_path[i] = -1
        return shortest_path
