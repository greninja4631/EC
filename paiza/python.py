def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(n - 1 - i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break  # 途中で入れ替えがなければソート済み
    return arr

# 実行例
arr = [3, 1, 4, 2]
print(bubble_sort(arr))


def mood_decorator(func):
    def wrapper(*args, **kwargs):
        print("🌟 Mood を取得します...")
        return func(*args, **kwargs)
    return wrapper

class Person:
    def __init__(self, name, mood):
        self.name = name
        self.__mood = mood

    @property
    @mood_decorator  # カスタムデコレーター適用
    def mood(self):
        return self.__mood

person = Person("Bob", "neutral")
print(person.mood) 



x = (1)
print(type(x))  # <class 'int'>

y = (1,)
print(type(y))  # <class 'tuple'>
