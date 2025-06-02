class Solution:
    def convertFive(self, n):
       
        
        s=str(n)
        s=s.replace('0','5')
        return int(s)