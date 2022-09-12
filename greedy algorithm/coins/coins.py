def change(N):
    cents = [100, 50, 25, 10, 5, 1]
    solution = []
    sum = 0

    i = 0   #find coin position in array
    while sum != N:
        if sum + cents[i] <= N:
            x = cents[i]
            sum += cents[i]
            solution.append(cents[i]) 
        elif i == len(cents):
            return 0
        else:
            i += 1
    return solution

if __name__ == "__main__":
    n = int(input("Wha't is the change? (in cents) "))
    solution = change(n)
    
    if solution: print(solution)
    else: print("No solution found")