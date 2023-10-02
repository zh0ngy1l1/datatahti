# https://cses.fi/dt/task/349, 1.10.2023
 
n, m, q = tuple([int(i) for i in input().split()])
rows = []
for _ in range(n):
    rows.append(input())
output = ""
 
for _ in range(q):
    result = 0
    rect = [int(i) - 1 for i in input().split()]
    for row in rows[rect[0]:rect[2] + 1]:
        result = result + row[rect[1]:rect[3] + 1].count("*")
    output = output + str(result) + "\n"
 
print(output[:-1])