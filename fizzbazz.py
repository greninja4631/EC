def fizzbazz(a):
    for num in range(1, 1+a):
        if num % 3 == 0 and num % 5 == 0:
            print("Fizzbazz")
         
        elif num % 3 == 0:
            print("Fizz")

        elif num % 5 == 0:
            print("bazz")

        else:
            print(num)

fizzbazz(100)