#Student: Gustavo Sampaio Lima
#ID: 12623992
from sys import setrecursionlimit
from functools import lru_cache

setrecursionlimit(5000)    
@lru_cache(maxsize=None)
def search_new_path(posY, posX):
    #out of limits
    if posY >= rows or posX >= columns: 
        return 0
    else:
        #final position
        if posY == rows-1 and posX == columns-1:
            return 1
        
        if(board[posY][posX] == '#'):
            return 0
        result = (search_new_path(posY+1, posX) + search_new_path(posY, posX+1)) % MOD
        return result 

MOD = 1000000007
rows, columns = [int(i) for i in input().split()]

board = []

for i in range(rows):
    new_column = input()
    new_column = [i for i in new_column]
    board.append(new_column)

print(search_new_path(0,0))

