def celsius_to_fahrenheit(celsuis : float) -> float:
    fahrenheit = celsuis * (9/5) + 32
    return fahrenheit

def fahrenheit_to_celsius(fahrenheit : float) -> float:
    celsuis = (fahrenheit - 32) * (5/9)
    return celsuis


num = float(input("Enter the temperature (can be float): "))

print("1 -> Celsius to Fahrenheit")
print("2 -> Fahrenheit to Celsius ")
match int(input("Enter conversion choice: ")):

    case 1:
        print("Fahrenheit -> %.2f" % celsius_to_fahrenheit(num))

    case 2:
        print("Celsius -> %.2f" % fahrenheit_to_celsius(num))

    case _:
        print("Invalid Choice!")
