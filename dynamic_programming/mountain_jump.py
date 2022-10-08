from functools import lru_cache
@lru_cache(maxsize=1024*1024) #by default
#Search for the minimum possible total energy cost incurred.
def search_best_path(mountain_pos): #Aplicando a programacao dinamica progressiva
    res1, res2 = 1000, 10000
    if mountain_pos+1 <= len(mountains): res1 = abs(mountains[mountain_pos] - mountains[mountain_pos + 1])
    if mountain_pos+2 <= len(mountains): res2 = abs(mountains[mountain_pos] - mountains[mountain_pos + 2])
    return min(res1, res2)

amount_mountains = int(input())
mountains = [int(i) for i in input().split()]
for i in range(amount_mountains):
    search_best_path(mountains[i])

print(search_best_path(0))
#Qual é o nosso caso base?
# Neste caso, vale pensar que o caso base seria a distância entre uma montanha e ela mesma (d = 0)
