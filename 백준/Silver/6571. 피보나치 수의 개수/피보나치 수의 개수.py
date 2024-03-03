

fibo = []

def init():
    fibo.append(1)
    fibo.append(2)
    while fibo[-1] + fibo[-2] <= 1e100:
        fibo.append(fibo[-1] + fibo[-2])
    


def main():
    while True:
        a, b = map(int, input().split())
        if a == 0 and b == 0:
            return
        ans = 0
        for i in fibo:
            if a <= i and i <= b:
                ans += 1
        print(ans)
    


if __name__ == "__main__":
    init()
    main()