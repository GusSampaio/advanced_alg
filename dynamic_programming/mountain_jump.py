from functools import lru_cache

#Search for the minimum possible total energy cost incurred.
@lru_cache(maxsize=None)
def search_best_path(mountain_pos):
    if mountain_pos < len(mountains) - 2: 
        possible_path1 = abs(mountains[mountain_pos + 1] - mountains[mountain_pos]) + search_best_path(mountain_pos + 1)
        possible_path2 = abs(mountains[mountain_pos + 2] - mountains[mountain_pos]) + search_best_path(mountain_pos + 2)
        return min(possible_path1, possible_path2)
    elif mountain_pos == len(mountains) - 2:
        return abs(mountains[mountain_pos+1] - mountains[mountain_pos])
    else:
        return 0

amount_mountains = int(input())
mountains = [int(i) for i in input().split()]

for i in range(amount_mountains, 0, -1): #Calculating all best paths, in reverse
    search_best_path(i)

print(search_best_path(0))  