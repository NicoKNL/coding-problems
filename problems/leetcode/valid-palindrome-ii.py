class Solution:
    def validPalindrome(self, s: str) -> bool:
        l = 0
        r = len(s) - 1

        Q = [[l, r, 0]]
        i = 0
        while i < len(Q):
            l, r, count = Q[i]
            i += 1
            if count > 1:
                continue
                
            if l >= r:
                return True
            
            
            if s[l] == s[r]:
                Q.append([l + 1, r - 1, count])
            else:
                if s[l + 1] == s[r]:
                    Q.append([l + 1, r, count + 1])
                if s[l] == s[r - 1]:
                    Q.append([l, r - 1, count + 1])
        
        return False
