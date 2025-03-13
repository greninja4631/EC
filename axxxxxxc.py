def fizzbazz():
    for i in range(5,101):
        if i % 3 == 0 and i % 5 == 0:
            print('fizzbazz')
        elif i % 3 == 0:
            print('fizz')
        elif i % 5 == 0:
            print('bazz')
        else:
            print(i)
fizzbazz()