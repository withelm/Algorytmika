from typing import List

class Solution:
    base = {}
    stop = False

    def solveSudoku(self, board: List[List[str]]) -> None:
        self.init()
        while (self.oblivius(board)):
            pass
        self.dfs(board)

    def legal(self, t: List[List[str]], find: List[int]) -> List[str]:
        if t[find[0]][find[1]] != ".":
            return []
        k = [0,0,0,0,0,0,0,0,0,0]
        for i in range(3):
            way = self.base[hash(tuple([find[0], find[1], i]))]
            for x in way:
                if t[x[0]][x[1]] != '.':
                    k[int(t[x[0]][x[1]])] += 1
        result = []
        for i in range(1, 10):
            if k[i] == 0:
                result.append(str(i))
        return result
    def check(self, t: List[List[str]]) -> bool:
        for i in range(9):
            for j in range(9):
                if (t[i][j] == '.'):
                    return False
        return True
    def dfs(self, t: List[List[str]]) -> None:
        if (self.stop):
            return
        if (self.check(t)):
            self.stop = True
            return
        for i in range(9):
            for j in range(9):
                next = self.legal(t, [i, j])
                if t[i][j] == '.' and len(next) == 0:
                    return
                for x in next:
                    t[i][j] = x
                    self.dfs(t)
                    if self.stop:
                        return
                    t[i][j] = '.'
                if t[i][j] == '.':
                    return
    def oblivius(self,  t: List[List[str]]) -> bool:
        isUp = False
        for i in range(9):
            for j in range(9):
                if (t[i][j] == '.'):
                    tmp = self.legal(t, [i,j])
                    if (len(tmp) == 1):
                        t[i][j] = tmp[0]
                        isUp = True
        return isUp


    def init(self) -> None:
        for j in range(9):
            for i in range(9):
                key = hash(tuple([j, 0, 0]))
                value = [j, i]
                if key in self.base:
                    self.base[key].append(value)
                else:
                    self.base[key] = [value]
        for j in range(9):
            for i in range(1, 9):
                self.base[hash(tuple([j, i, 0]))] = self.base[hash(tuple([j, 0, 0]))]
        for j in range(9):
            for i in range(9):
                key = hash(tuple([0, j, 1]))
                value = [i, j]
                if key in self.base:
                    self.base[key].append(value)
                else:
                    self.base[key] = [value]
        for j in range(9):
            for i in range(1, 9):
                self.base[hash(tuple([i, j, 1]))] = self.base[hash(tuple([0, j, 1]))]
        for ii in range(0, 7, 3):
            for jj in range(0, 7, 3):
                tmp = []
                for i in range(3):
                    for j in range(3):
                        tmp.append([i + ii, j + jj])
                for i in range(3):
                    for j in range(3):
                        self.base[hash(tuple([i + ii, j + jj, 2]))] = tmp

                
                

    def printBoard(self, board: List[List[str]]) -> None:
        for row in board:
            for cell in row:
                print(cell, end='')
            print("")
        print("")

