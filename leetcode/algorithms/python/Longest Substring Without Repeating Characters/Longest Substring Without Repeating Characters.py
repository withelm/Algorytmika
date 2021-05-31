class Solution:
    tab = {}

    def check(self, s: chr) -> bool:
        if (s not in self.tab):
            return True
        if (self.tab[s] > 0):
            return False
        return True

    def lengthOfLongestSubstring(self, s: str) -> int:
        if (len(s) == 0):
            return 0
        if (len(s) == 1):
            return 1

        result = 1
        begin = 0
        end = 1

        self.tab[s[begin]] = 1
        while(begin < len(s)):
            if (begin >= end):
                end = begin + 1
                self.tab = {}
                self.tab[s[begin]] = 1
            while(end < len(s) and self.check(s[end])):
                if s[end] in self.tab:
                    self.tab[s[end]] += 1
                else:
                    self.tab[s[end]] = 1
                end += 1
            val = end - begin
            if (val > result):
                result = val
            self.tab[s[begin]] -= 1
            begin += 1
        return result
