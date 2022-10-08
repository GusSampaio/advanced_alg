def search_for_new_word(word, matrix, board_limits, position_letter):
    if 
    

def main():
    board_limits = list(map(int, input.split()))
    if 0 in board_limits:
        print("Impossible result")
        return

    matrix = []
    for i in range(board_limits[i]):
        matrix.append(list(map(int, input.split())))

    word_size = int(input()) #unseless
    word = input()

    result = search_for_new_word(word, matrix, board_limits, 0)
    print("Yes" if result else "No")

main()   