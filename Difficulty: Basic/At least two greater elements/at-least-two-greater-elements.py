class Solution:
    def findElements(self,arr):
        # Your code goes here
        arr.sort()
        return arr[:-2]