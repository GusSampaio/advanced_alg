#Student: Gustavo Sampaio Lima
#ID: 12623992
def lis(input_array, array_size):
    lis = [1] * array_size
    for i in range(1, array_size):
        for j in range(0,i):
            if input_array[i] > input_array[j] and lis[i] < lis[j] + 1:
                lis[i] = lis[j] + 1

    maximum = 0
    for i in range(array_size):
        maximum = max(maximum, lis[i])
 
    return maximum
    
array_size = int(input())
input_array = [int(i) for i in input().split()]
print(lis(input_array, array_size))