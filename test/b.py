def kansuu(x):
    if x % 3 == 0 and x % 5 == 0:
        result = "fizzbazz"

    elif x % 3 == 0:
        result = "fizz"

    elif x % 5 == 0:
        result = "bazz"

    else:
        result = x

    return result