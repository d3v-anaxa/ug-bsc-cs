# 1 - 2/2! + 3/3! - 4/4! ... +/- n/n!
def factorial(n : int) -> int:
    if (n < 2):
        return n
    else:
        return n * factorial(n-1)

def calculate_result(n : int) -> float:
    res = 0
    while n != 0:
        if n % 2 == 1:
            res += n / factorial(n)
        else:
            res -= n / factorial(n)

        n -= 1
    return res


num = int(input("Enter the number to get factorial: "))
if num < 1:
    print("!Enter number greater than 0")
else:
    print("Result -> %.2f" % calculate_result(num))
