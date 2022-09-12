def new_pairs(species, amnt_chambers, pairs, j):
    for i in range(amnt_chambers):
        pairs[j] = species[i]
        pairs[j+1] = species[amnt_chambers*2 - 1 - i]
        j+=2

def calc_imbalance(amnt_chambers, pairs, AM):
    imbalance, result, CM = 0, 0, 0

    for i in range(0, amnt_chambers*2, 2):
        CM = pairs[i] + pairs[i+1]
        result = abs(CM - AM)
        imbalance += result

    return imbalance

if __name__ == "__main__":
    amnt_chambers, amnt_species, sets = 0, 0, 0
    while True:
        try:    
            entry = list(map(int,input().split()))
            amnt_chambers = entry[0]
            amnt_species = entry[1]
            species = []
            sets += 1
            AM = 0

            new_species = list(map(int,input().split()))
            for i in new_species: 
                species.append(i)
                AM += i
            
            AM = AM / amnt_chambers

            aux = amnt_species

            while(aux < amnt_chambers*2):
                species.append(0)
                aux += 1

            species.sort()

            pairs = [0]*(amnt_chambers*2)

            new_pairs(species, amnt_chambers, pairs, 0)

            print("Set #", sets, sep='')
            for i in range(0, amnt_chambers*2, 2):
                print(" ", int(i/2), ": ",sep ='', end="")
                if pairs[i]>0: print(pairs[i], end=" ")
                if pairs[i+1]>0: print(pairs[i+1], end="")
                print()

            imbalance = calc_imbalance(amnt_chambers, pairs, AM)
            print(f'IMBALANCE = {imbalance:,.5f}', '\n')

        except EOFError:
            break