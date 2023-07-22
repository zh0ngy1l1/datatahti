#// https://cses.fi/alon/task/1070/ 22.7.2023

n = int(input("")) # 1 makes 1
if n == 1:
    print(1)
elif n < 4: #2 and 3 no solution
    print("NO SOLUTION")
elif n == 4: # specifically for 2
    print("3 1 4 2")
else: # algorithm works for n > 4
    out_str = " ".join([str(i) for i in range(1, n+1, 2)]) + " " +  " ".join([str(i) for i in range(2, n+1, 2)])
    print(out_str)