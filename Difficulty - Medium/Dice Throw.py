class Solution:
    def noOfWays(self, m, n, x):
        reachable = defaultdict(int, {0: 1})
        for _ in range(n):
            new_reachable = defaultdict(int)
            for k, v in reachable.items():
                for km in range(k + 1, min(x, k + m) + 1):
                    new_reachable[km] += v
            reachable = new_reachable
        return reachable[x]