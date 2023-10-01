# // https://cses.fi/alon/task/1071/ 23.7.2023

import json

def generate_spiral(n):
    number_spiral = [[0 for _ in range(n)] for _ in range(n)]
    direction = 0  # to the right
    row = 0
    column = 0
    for number in range(1, n**2 + 1):
        number_spiral[row][column] = number

        if direction == 0:
            direction = 1

            column += 1

        elif direction == 1:
            if row == column - 1:
                direction = 2

            row += 1

        elif direction == 2:
            if column == 1:
                direction = 3

            column -= 1

        elif direction == 3:
            direction = 4

            row += 1

        elif direction == 4:
            if row == column + 1:
                direction = 5

            column += 1

        elif direction == 5:
            if row == 1:
                direction = 0

            row -= 1

    return number_spiral


spiral = generate_spiral(int(input()))
with open("spiral.json", "w") as f:
    f.writelines(json.dumps(spiral))
