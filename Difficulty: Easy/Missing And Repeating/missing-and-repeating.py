class Solution:
    def findTwoElement(self, arr):
        n = len(arr)
        repeating = -1
        missing = -1

        # Step 1: Find repeating using marking
        for i in range(n):
            val = abs(arr[i])
            if arr[val - 1] < 0:
                repeating = val
            else:
                arr[val - 1] *= -1

        # Step 2: Find missing (index which is still positive)
        for i in range(n):
            if arr[i] > 0:
                missing = i + 1
                break

        return [repeating, missing]
