class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        size = len(board)
        l = [0 for x in range(size + 1)]
        for i in range(size):
            for u in range(size + 1):
                l[u] = 0
            for j in range(size):
                if board[i][j] == '.':
                    continue
                if l[int(board[i][j])] == 1:
                    return False
                else:
                    l[int(board[i][j])] += 1
        for i in range(size):
            for u in range(size + 1):
                l[u] = 0
            for j in range(size):
                if board[j][i] == '.':
                    continue
                if l[int(board[j][i])] == 1:
                    return False
                else:
                    l[int(board[j][i])] += 1
        for i in range(0, size - 1, 3):
            for j in range(0, size - 1, 3):
                for u in range(size + 1):
                    l[u] = 0
                for m in range(3):
                    for n in range(3):
                        if board[i + m][j + n] == '.':
                            continue
                        int(board[i + m][j + n])
                        if l[int(board[i + m][j + n])] == 1:
                            return False
                        else:
                            l[int(board[i + m][j + n])] += 1
        return True
