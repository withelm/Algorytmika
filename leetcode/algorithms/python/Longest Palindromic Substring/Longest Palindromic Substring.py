class Solution:
    
    n = 0
    vis = []
    dp = []
    word = ""

    def dfs(self, x: int, y: int) -> int:
        if (x < 0 or y < 0 or y >= self.n or x >= self.n or x > y):
            return 0
        if (self.vis[x][y] == True):
            return self.dp[x][y]
        self.vis[x][y] = True
        if (self.word[x] == self.word[y]):
            ans = self.dfs(x + 1, y - 1)
            if (ans > 0):
                self.dp[x][y] = ans + 2
            else:
                self.dp[x][y] = 0
        return 0


    def longestPalindrome(self, s: str) -> str:
        self.n = len(s)
        if (self.n == 0):
            return ""
        self.word = s
        for i in range(self.n):
            self.dp.append([])
            self.vis.append([])
            for j in range(self.n):
                self.dp[i].append(0)
                self.vis[i].append(False)
        length = -1
        x = -1
        y = -1
        for i in range(self.n):
            self.vis[i][i] = True
            self.dp[i][i] = 1
            if (i + 1 < self.n and s[i] == s[i + 1]):
                self.vis[i][i+1] = True
                self.dp[i][i + 1] = 2
        for i in range(self.n):
            for j in range(self.n):
                self.dp[i][j] = self.dfs(i, j)
                if (self.dp[i][j] > length):
                    x = i
                    y = j
                    length = self.dp[i][j]
        return self.word[x:y]