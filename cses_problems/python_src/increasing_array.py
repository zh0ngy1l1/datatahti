#// https://cses.fi/alon/task/1068/ 12.3.2023

size = int(input(""))
input_array = [int(num) for num in input("").split()]
largest = 0
total_moves = 0
for num in input_array:
    if largest <= num:
        largest = num
    else:
        moves = largest - num
        total_moves += moves
print(total_moves)