def factorial(n : int) -> int:
    if (n < 2):
        return n
    else:
        return n * factorial(n-1)

num = int(input("Enter the number to get factorial: "))
if num < 1:
    print("!Enter number greater than 0")
else:
    print("Factorial -> %d" % factorial(num))
