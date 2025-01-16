import random

n = 10**5
m = 10**5

def r():
    return round(min(9E8+(random.randint(1, 1E8)//(random.random()**(-0.001))), 10**9))

def run():
    output_str = f"{n} {m}\n"
    s = []
    for _ in range(n):
        s.append(r())
    
    output_str += " ".join(map(str, s))
    
    if True:
        output_str += "\n"
        s = []
        for _ in range(n):
            s.append(r())
        
        output_str += " ".join(map(str, s))
    
    with open("input.txt", "w", encoding="utf-8") as f:
        f.write(output_str)

if __name__ == "__main__":
    run()