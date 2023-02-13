class Solution:
    def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
        min_fuel = 0
        # Construct the adj list first
        adj_list = [[] for i in range(len(roads)+1)]
        for road in roads:
            adj_list[road[0]].append(road[1])
            adj_list[road[1]].append(road[0])
        
        # variant of dfs
        # Basically we check now many subnodes a node has
        # then we calulate num of the cars needed for the edge from node to its parent
        # Finally, we return the sum of num of cars for all edges
        def dfs(parent, node):
            nonlocal min_fuel  # have to make it nonlocal
            subnode = 0
            for nb in adj_list[node]:
                if nb != parent:
                    subnode += dfs(node, nb)
            if node != 0:
                min_fuel += math.ceil((subnode+1) / seats)
            return subnode + 1
        dfs(-1, 0)
        return min_fuel
