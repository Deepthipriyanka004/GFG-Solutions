class Solution:
    # Complete this function
    def printTillN(self, N):
        if N == 0:
            return
        self.printTillN(N - 1)
        print(N, end=" ")
