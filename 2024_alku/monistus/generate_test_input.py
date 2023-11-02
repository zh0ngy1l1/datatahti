import random


letters = [i for i in "abcdefghijklmnopqrstuvwxyz"]

l = 20
output = ""

active_numbers = []
numbers_lifespan = []

for _ in range(l):
    
    for i in range(len(numbers_lifespan)):
        if numbers_lifespan[i] == 0:
            active_numbers[i] = 0
            
    while 0 in numbers_lifespan:
        numbers_lifespan.remove(0)
    
    while 0 in active_numbers:
        active_numbers.remove(0)
        
    numbers_lifespan = [i-1 for i in numbers_lifespan]
    
        
    if 1 in active_numbers:
        output += random.choice(letters)
        continue
    
    if random.randint(1, 3) == 1:
        if len(active_numbers) == 0:
            n = random.randint(1, 9)
        else:
            n = random.randint(1, min(active_numbers) - 1)
        active_numbers.append(n)
        numbers_lifespan.append(n)
        output += str(n)
    else:
        output += random.choice(letters)
    
output+="olabipihale"
    
print(output)