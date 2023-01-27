class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        counter = collections.Counter(words)
        freq = [(counter[s] * -1, s) for s in counter]
        heapq.heapify(freq)
        return [heapq.heappop(freq)[1] for i in range(k)]
