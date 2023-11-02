a=input()
while True:
    if a.isalpha():
        break
    for i in range(len(a)):
        if a[i].isdigit():
            break
    a = a[:i]+a[(i+1):(i+1+int(a[i]))]+a[(i+1):]
print(a)