numbers = [3, 7, 2, 8, 5]

max_value = numbers[0]

for number in numbers[1:]:
    if number > max_value:
        max_value = number
print(max_value)