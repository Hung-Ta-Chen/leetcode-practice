class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # No max heap in heapq, so we have to multiply all elements by -1
        for i in range(len(stones)):
            stones[i] *= -1
        heapq.heapify(stones)
        while len(stones) > 1:
            max1 = heapq.heappop(stones)
            max2 = heapq.heappop(stones)
            if max1 != max2:
                heapq.heappush(stones, max1-max2)
        if len(stones) == 0:
            return 0
        else:
            return heapq.heappop(stones) * -1
