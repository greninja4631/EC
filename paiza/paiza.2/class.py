# 78. クラスの定義
class Animal:
    species = "Unknown"  # 88. クラス変数

    # 79. クラスの初期化とクラス変数
    def __init__(self, name, age):
        self.name = name  # インスタンス変数
        self.age = age

    # 80. コンストラクタとデストラクタ
    def __del__(self):
        print(f"{self.name} is being deleted")

    # 82. メソッドのオーバーライドとsuperによる親のメソッドの呼び出し
    def speak(self):
        return "Some sound"

# 81. クラスの継承
class Dog(Animal):
    species = "Canis lupus familiaris"

    def __init__(self, name, age, breed):
        super().__init__(name, age)  # 親クラスのコンストラクタを呼ぶ
        self.breed = breed

    # 82. メソッドのオーバーライド
    def speak(self):
        
        return "Woof!"

# 83. プロパティーを使った属性の設定
class Cat(Animal):
    def __init__(self, name, age):
        super().__init__(name, age)
        self._mood = "happy"

    @property
    def mood(self):
        return self._mood

    @mood.setter
    def mood(self, value):
        if value in ["happy", "angry", "sleepy"]:
            self._mood = value
        else:
            raise ValueError("Invalid mood")

# 84. クラスを構造体として扱う時の注意点
from collections import namedtuple
Point = namedtuple("Point", ["x", "y"])  # 構造体のようなデータ構造

# 85. ダックタイピング
class Bird:
    def fly(self):
        return "Flying high!"

class Airplane:
    def fly(self):
        return "Taking off!"

def perform_flight(obj):
    return obj.fly()  # ダックタイピング: "fly" メソッドを持つなら動作する

# 86. 抽象クラス
from abc import ABC, abstractmethod

class Vehicle(ABC):
    @abstractmethod
    def move(self):
        pass

class Car(Vehicle):
    def move(self):
        return "Driving on the road"

# 87. 多重継承
class Pet:
    def show_affection(self):
        return "Shows affection"

class FriendlyDog(Dog, Pet):
    pass

# 89. クラスメソッドとスタティックメソッド
class Utility:
    value = 42

    @classmethod
    def get_value(cls):
        return cls.value  # クラスメソッド

    @staticmethod
    def greet():
        return "Hello from Utility!"  # スタティックメソッド

# 90. 特殊メソッド
class CustomNumber:
    def __init__(self, value):
        self.value = value

    def __add__(self, other):
        return CustomNumber(self.value + other.value)

    def __str__(self):
        return f"CustomNumber({self.value})"

# 動作確認
if __name__ == "__main__":
    dog = Dog("Rex", 5, "Golden Retriever")
    print(dog.speak())  # Woof!
    
    cat = Cat("Milo", 3)
    cat.mood = "sleepy"
    print(cat.mood)  # sleepy

    p = Point(10, 20)
    print(p)  # Point(x=10, y=20)

    print(perform_flight(Bird()))  # Flying high!
    print(perform_flight(Airplane()))  # Taking off!

    car = Car()
    print(car.move())  # Driving on the road

    friendly_dog = FriendlyDog("Buddy", 4, "Labrador")
    print(friendly_dog.show_affection())  # Shows affection

    print(Utility.get_value())  # 42
    print(Utility.greet())  # Hello from Utility!

    num1 = CustomNumber(10)
    num2 = CustomNumber(20)
    print(num1 + num2)  # CustomNumber(30)









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