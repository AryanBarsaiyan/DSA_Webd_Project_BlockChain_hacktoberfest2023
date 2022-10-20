class Solution:
    def makeLargestSpecial(self, S: str) -> str:
        balance = l = 0
        subResults = []
        for r in range(len(S)):
            if S[r] == '0':
                balance -= 1
            else:
                balance += 1
                
            if balance == 0:
                subResults.append("1" + self.makeLargestSpecial(S[l + 1 : r]) + "0")
                l = r + 1
            
        subResults.sort(reverse = True)
        return ''.join(subResults)
