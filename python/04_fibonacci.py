def fibonacci(x : int) -> None:
    first = 0
    second = 1
    print("Fibonacci series : ", end = "")
    for _ in range(x):
        print(f" {first}", end = "")
        second = first + second
        first = second - first
    print()

term = int(input("Enter the term to get fibonacci series: "))
if term < 1:
    print("!Enter a term greater than 0")
else:
    fibonacci(term)
