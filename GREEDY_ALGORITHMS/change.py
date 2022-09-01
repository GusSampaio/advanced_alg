#Suppose I need to “make change” of $2.89. The best solution, that is, the smallest number of
# possible coins to get the value, consists of 10 coins: 2 worth 100, 3 worth 25, 1 worth 10
# and 4 of value 1. In general, we act like a greedy algorithm: at each stage we add ´
# the most valuable currency possible, so as not to exceed the amount necessary

def change(N):
    cents = [100, 50, 25, 10, 5, 1]
    solution = []
    sum = 0

    i = 0   #find coin position in array
    x = 0   #checks if there's a possible coin
    while sum != N:
        if sum + cents[i] <= N:
            x = cents[i]
            sum += cents[i]
            solution.append(cents[i]) 
        elif x == 0:
            return "No solution found!"
        else:
            i += 1
    return solution

if __name__ == "__main__":
    n = int(input("Wha't is the change? (in cents) "))
    solution = change(n)
    print(solution)
