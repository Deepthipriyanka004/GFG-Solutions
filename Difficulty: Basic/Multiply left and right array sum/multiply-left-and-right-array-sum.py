#User function Template for python3

class Solution:
    def multiply(self, arr):
        # Code here
         return sum(arr[:len(arr)//2])*sum(arr[len(arr)//2:])