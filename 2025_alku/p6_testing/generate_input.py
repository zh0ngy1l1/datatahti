import random


def r1():
    return random.randint(1, 200)

n = 3
m = 15

mina = min([r1() for _ in range(10)]); maxa = max([r1() for _ in range(10)])


def r2():
    if random.random() > 0.7:
        return random.randint(mina, maxa)
    return random.randint(mina, maxa//4 + (3*mina)//4)

def run():
    output_str = f"{n} {m}\n"
    s = []
    for _ in range(n):
        s.append(r2())
    s.sort(reverse=True)
    output_str += " ".join(map(str, s))
    with open("input.txt", "w", encoding="utf-8") as f:
        f.write(output_str)

if __name__ == "__main__":
    run()