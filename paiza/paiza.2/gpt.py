class Pokemon:
    def __init__(self, name, level):
        self.name = name
        self.__level = level

    @property
    def level(self):
        return self.__level

    @level.setter
    def level(self, new_level):  # セッター（レベルを変更する）
        if new_level > self.__level:  # 🔥 レベルは上がるだけ！
            self.__level = new_level
        else:
            print("❌ レベルは下げられない！")

pikachu = Pokemon("ピカチュウ", 10)
pikachu.level = 15  # ✅ レベルアップ！
print(pikachu.level)  # → 15
pikachu.level = 5  # ❌ 失敗！ レベルは下がらない




class Pokemon:
    def __init__(self, name, level):
        self.name = name
        self.__level = level  # private（外部からアクセス不可）

pikachu = Pokemon("ピカチュウ", 10)
print(pikachu.name)  # ✅ 見れる
print(pikachu.__level)  # ❌ エラー！